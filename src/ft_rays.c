/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:51:10 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/13 18:29:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

float	ft_normalize(float ray_ang)
{
	ray_ang = remainder(ray_ang, 2 * M_PI);
	if (ray_ang < 0)
		ray_ang = 2 * M_PI + ray_ang;
	return (ray_ang);
}

float	ft_distance(float x1, float x2, float y1, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ft_cast_one(t_vars *data, float angle, int id)
{
	t_cast	r;

	r.angle = ft_normalize(angle);
	// initialisation
	r.is_down = r.angle > 0 && r.angle < M_PI;
	r.is_up = !r.is_down;
	r.is_right = r.angle < 0.5 * M_PI || r.angle > 1.5 * M_PI;
	r.is_left = !r.is_right;
	// Horizontal intersection
	//////////////////////////
	r.found_hor_wall_hit = 0;
	r.hor_wall_hit_x = 0;
	r.hor_wall_hit_y = 0;
	r.hor_wall_cont = 0;
	// Find the y-coordinate of the closest horizontal grid intersection
	r.y_inters = floor(data->player.y / data->data.cub_size)
		* data->data.cub_size;
	if (r.is_down)
		r.y_inters += data->data.cub_size;
	// Find the x-coordinate of the closest horizontal grid intersection
	r.x_inters = data->player.x + (r.y_inters - data->player.y) / tan(r.angle);
	// Calculate the increment xstep and ystep
	r.y_step = data->data.cub_size;
	if (r.is_up)
		r.y_step *= -1;
	r.x_step = data->data.cub_size / tan(r.angle);
	if (r.is_left && r.x_step > 0)
		r.x_step *= -1;
	if (r.is_right && r.x_step < 0)
		r.x_step *= -1;
	// incrementing untill we found an horizontal intersection
	r.next_touch_hor_x = r.x_inters;
	r.next_touch_hor_y = r.y_inters;
	while (r.next_touch_hor_x >= 0
		&& r.next_touch_hor_x <= data->data.grid_width
		&& r.next_touch_hor_y >= 0
		&& r.next_touch_hor_y <= data->data.grid_height)
	{
		r.x_check = r.next_touch_hor_x;
		r.y_check = r.next_touch_hor_y;
		if (r.is_up)
			r.y_check += -1;
		if (its_wall(data, r.x_check, r.y_check))
		{
			r.hor_wall_hit_x = r.next_touch_hor_x;
			r.hor_wall_hit_y = r.next_touch_hor_y;
			r.hor_wall_cont = data->map[(int)floor(r.y_check
				/ data->data.cub_size)][(int)floor(r.x_check
				/ data->data.cub_size)];
			r.found_hor_wall_hit = 1;
			break ;
		}
		else
		{
			r.next_touch_hor_x += r.x_step;
			r.next_touch_hor_y += r.y_step;
		}
	}
	// vertical intersection
	//////////////////////////
	r.found_ver_wall_hit = 0;
	r.ver_wall_hit_x = 0;
	r.ver_wall_hit_y = 0;
	r.ver_wall_cont = 0;
	// Find the x-coordinate of the closest horizontal grid intersection
	r.x_inters = floor(data->player.x / data->data.cub_size)
		/ data->data.cub_size;
	if (r.is_right)
		r.x_inters += data->data.cub_size;
	// Find the y-coordinate of the closest horizontal grid intersection
	r.y_inters = data->player.y + (r.x_inters - data->player.x) * tan(r.angle);
	// Calculate the increment xstep and ystep
	r.x_step = data->data.cub_size;
	if (r.is_left)
		r.x_step *= -1;
	r.y_step = data->data.cub_size * tan(r.angle);
	if (r.is_up && r.y_step > 0)
		r.y_step *= -1;
	if (r.is_down && r.y_step < 0)
		r.y_step *= -1;
	r.next_touch_ver_x = r.x_inters;
	r.next_touch_ver_y = r.y_inters;
	// looping until we find a wall
	while (r.next_touch_ver_x >= 0
		&& r.next_touch_ver_x <= data->data.grid_width
		&& r.next_touch_ver_y >= 0
		&& r.next_touch_ver_y <= data->data.grid_height)
	{
		r.x_check = r.next_touch_ver_x;
		if (r.is_left)
			r.x_check += -1;
		r.y_check = r.next_touch_ver_y;
		if (its_wall(data, r.x_check, r.y_check))
		{
			r.ver_wall_hit_x = r.next_touch_ver_x;
			r.ver_wall_hit_y = r.next_touch_ver_y;
			r.ver_wall_cont = data->map[(int)floor(r.y_check
				/ data->data.cub_size)][(int)floor(r.x_check
				/ data->data.cub_size)];
			r.found_ver_wall_hit = 1;
			break ;
		}
		else
		{
			r.next_touch_ver_x += r.x_step;
			r.next_touch_ver_y += r.y_step;
		}
	}
	if (r.found_hor_wall_hit)
		r.hor_dist = ft_distance(data->player.x, data->player.y,
			r.hor_wall_hit_x, r.hor_wall_hit_y);
	else
		r.hor_dist = DBL_MAX;
	if (r.found_ver_wall_hit)
		r.ver_dist = ft_distance(data->player.x, data->player.y,
			r.ver_wall_hit_x, r.ver_wall_hit_y);
	else
		r.ver_dist = DBL_MAX;
	if (r.hor_dist < r.ver_dist)
	{
		data->rays[id].distance = r.hor_dist;
		data->rays[id].wall_hit_x = r.hor_wall_hit_x;
		data->rays[id].wall_hit_y = r.hor_wall_hit_y;
		data->rays[id].wall_content = r.hor_wall_cont;
		data->rays[id].is_ver = 0;
	}
	else
	{
		data->rays[id].distance = r.ver_dist;
		data->rays[id].wall_hit_x = r.ver_wall_hit_x;
		data->rays[id].wall_hit_y = r.ver_wall_hit_y;
		data->rays[id].wall_content = r.ver_wall_cont;
		data->rays[id].is_ver = 1;
	}
	data->rays[id].angle = r.angle;
	data->rays[id].is_up = r.is_up;
	data->rays[id].is_down = r.is_down;
	data->rays[id].is_left = r.is_left;
	data->rays[id].is_right = r.is_right;
}

void	ft_cast_all_rays(t_vars *data)
{
	int		i;
	float	ray_angle;

	ray_angle = data->player.rotation_angle - FOV / 2;
	ray_angle = ft_normalize(ray_angle);
	i = -1;
	while (++i < data->data.num_rays)
	{
		ft_cast_one(data, ray_angle, i);
		ray_angle += (float)FOV / data->data.num_rays;
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
		ft_line(data, tmp, YELLOW);
	}
}
