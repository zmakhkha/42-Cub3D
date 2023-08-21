/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:45:07 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/15 17:39:55 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

double	ft_normalize(double ray_ang)
{
	ray_ang = remainder(ray_ang, 2 * M_PI);
	if (ray_ang < 0)
		ray_ang = 2 * M_PI + ray_ang;
	return (ray_ang);
}

double	ft_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ft_init_ray(t_vars *data, t_cast *r)
{
	(void)data;
	r->is_down = r->angle > 0 && r->angle < M_PI;
	r->is_up = !r->is_down;
	r->is_left = r->angle > M_PI / 2 && r->angle < 1.5 * M_PI;
	r->is_right = !r->is_left;
	r->found_hor_wall_hit = 0;
	r->hor_wall_hit_x = 0;
	r->hor_wall_hit_y = 0;
	r->hor_wall_cont = 0;
	r->found_ver_wall_hit = 0;
	r->ver_wall_hit_x = 0;
	r->ver_wall_hit_y = 0;
}

void	ft_intersection(t_vars *data, t_cast *r, int type)
{
	if (type == HOR)
	{
		r->y_inters = floor(data->player.y / data->data.cub_size)
			* data->data.cub_size;
		if (r->is_down)
			r->y_inters += data->data.cub_size;
		else
			r->y_inters += 0;
		r->x_inters = (data->player.x + (r->y_inters - data->player.y) \
			/ tan(r->angle));
	}
	else if (type == VER)
	{
		r->x_inters = floor(data->player.x / data->data.cub_size) \
			* data->data.cub_size;
		if (r->is_right)
			r->x_inters += data->data.cub_size;
		else
			r->x_inters += 0;
		r->y_inters = (data->player.y + (r->x_inters - data->player.x) \
			* tan(r->angle));
	}
}

void	ft_steps(t_vars *data, t_cast *r, int type)
{
	if (type == HOR)
	{
		r->y_step = data->data.cub_size;
		if (r->is_up)
			r->y_step *= -1;
		r->x_step = data->data.cub_size / tan(r->angle);
		if ((r->is_left && r->x_step > 0) || (r->is_right && r->x_step < 0))
			r->x_step *= -1;
		r->next_touch_hor_x = r->x_inters;
		r->next_touch_hor_y = r->y_inters;
	}
	else if (type == VER)
	{
		r->x_step = data->data.cub_size;
		if (r->is_left)
			r->x_step *= -1;
		r->y_step = data->data.cub_size * tan(r->angle);
		if ((r->is_up && r->y_step > 0) || (r->is_down && r->y_step < 0))
			r->y_step *= -1;
		r->next_touch_ver_x = r->x_inters;
		r->next_touch_ver_y = r->y_inters;
	}
}
