/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:51:10 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 15:53:15 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_hor_loop(t_vars *data, t_cast *r)
{
	int	a;

	while (r->next_touch_hor_x >= 0
		&& r->next_touch_hor_x <= data->data.grid_width
		&& r->next_touch_hor_y >= 0
		&& r->next_touch_hor_y <= data->data.grid_height)
	{
		a = 0;
		if (r->is_up)
			a = 1;
		if (its_wall(data, r->next_touch_hor_x, r->next_touch_hor_y - a) == 1)
		{
			r->found_hor_wall_hit = 1;
			r->hor_wall_hit_x = r->next_touch_hor_x;
			r->hor_wall_hit_y = r->next_touch_hor_y;
			break ;
		}
		else
		{
			r->next_touch_hor_x += r->x_step;
			r->next_touch_hor_y += r->y_step;
		}
	}
}

void	ft_ver_loop(t_vars *data, t_cast *r)
{
	int	a;

	while (r->next_touch_ver_x >= 0
		&& r->next_touch_ver_x <= data->data.grid_width
		&& r->next_touch_ver_y >= 0
		&& r->next_touch_ver_y <= data->data.grid_height)
	{
		a = 0;
		if (r->is_left)
			a = 1;
		if (its_wall(data, r->next_touch_ver_x - a, r->next_touch_ver_y))
		{
			r->found_ver_wall_hit = 1;
			r->ver_wall_hit_x = r->next_touch_ver_x;
			r->ver_wall_hit_y = r->next_touch_ver_y;
			break ;
		}
		else
		{
			r->next_touch_ver_x += r->x_step;
			r->next_touch_ver_y += r->y_step;
		}
	}
}

void	ft_cast_one(t_vars *data, double angle, int id)
{
	t_cast	r;

	r.angle = ft_normalize(angle);
	ft_init_ray(data, &r);
	ft_intersection(data, &r, HOR);
	ft_steps(data, &r, HOR);
	ft_hor_loop(data, &r);
	ft_intersection(data, &r, VER);
	ft_steps(data, &r, VER);
	ft_ver_loop(data, &r);
	ft_store(data, &r, id);
}

void	ft_cast_all_rays(t_vars *data)
{
	int		i;
	double	ray_angle;

	ray_angle = data->player.rotation_angle - data->data.half_fov;
	ray_angle = ft_normalize(ray_angle);
	i = -1;
	while (++i < data->data.num_rays)
	{
		ft_cast_one(data, ray_angle, i);
		ray_angle += data->data.fov_angle / data->data.num_rays;
		ray_angle = ft_normalize(ray_angle);
	}
}

void	ft_render_rays(t_vars *data)
{
	t_line	tmp;
	int		i;

	i = -1;
	ft_cast_all_rays(data);
	while (++i < data->data.num_rays)
	{
		tmp.dx = data->rays[i].wall_hit_x;
		tmp.dy = data->rays[i].wall_hit_y;
		tmp.ox = data->player.x;
		tmp.oy = data->player.y;
	}
}
