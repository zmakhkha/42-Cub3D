/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:51:10 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/25 10:33:01 by zmakhkha         ###   ########.fr       */
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

double	ft_distance(double x1, double x2, double y1, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ft_init_ray(t_vars *data, t_cast *r)
{
	r->is_down = r->angle > 0 && r->angle < M_PI;
	r->is_up = !r->is_down;
	r->is_left = r->angle > M_PI / 2 && r->angle < 3 * M_PI / 2;
	r->is_right = !r->is_left;
	// horizontal
	r->found_hor_wall_hit = 0;
	r->hor_wall_hit_x = 0;
	r->hor_wall_hit_y = 0;
	r->hor_wall_cont = 0;
	// vertical
	r->found_ver_wall_hit = 0;
	r->ver_wall_hit_x = 0;
	r->ver_wall_hit_y = 0;
}

void	ft_intersection(t_vars *data, t_cast *r, int type)
{
	// Horizontal intersection
	if (type == HOR)
	{
		r->y_inters = floor(data->player.y / data->data.cub_size)
			* data->data.cub_size;
		r->y_inters += r->is_down ? data->data.cub_size : 0;
		r->x_inters = data->player.x + (r->y_inters - data->player.y)
			/ tan(r->angle);
	}
	else if (type == VER)
	{
		r->x_inters = floor(data->player.x / data->data.cub_size)
			* data->data.cub_size;
		r->x_inters += r->is_right ? data->data.cub_size : 0;
		r->y_inters = data->player.y + (r->x_inters - data->player.x)
			* tan(r->angle);
	}
}

void	ft_steps(t_vars *data, t_cast *r, int type)
{
	if (type == HOR)
	{
		r->y_step = data->data.cub_size;
		r->y_step *= r->is_up ? -1 : 1;
		r->x_step = data->data.cub_size / tan(r->angle);
		r->x_step *= (r->is_left && r->x_step > 0) ? -1 : 1;
		r->x_step *= (r->is_right && r->x_step < 0) ? -1 : 1;
		r->next_touch_hor_x = r->x_inters;
		r->next_touch_hor_y = r->y_inters;
	}
	else if (type == VER)
	{
		r->x_step = data->data.cub_size;
		r->x_step *= r->is_left ? -1 : 1;
		r->y_step = data->data.cub_size * tan(r->angle);
		r->y_step *= (r->is_up && r->y_step > 0) ? -1 : 1;
		r->y_step *= (r->is_down && r->y_step < 0) ? -1 : 1;
		r->next_touch_ver_x = r->x_inters;
		r->next_touch_ver_y = r->y_inters;
	}
}
void	ft_store(t_vars *data, t_cast *r, int id)
{
	// Comparing and storing the smallest value
	r->hor_dist = r->found_hor_wall_hit ? ft_distance(data->player.x,
		data->player.y, r->hor_wall_hit_x, r->hor_wall_hit_y) : DBL_MAX;
	r->ver_dist = r->found_ver_wall_hit ? ft_distance(data->player.x,
		data->player.y, r->ver_wall_hit_x, r->ver_wall_hit_y) : DBL_MAX;
	data->rays[id].angle = r->angle;
	data->rays[id].distance = (r->hor_dist < r->ver_dist) ? r->hor_dist : r->ver_dist;
	data->rays[id].wall_hit_x = (r->hor_dist < r->ver_dist) ? r->hor_wall_hit_x : r->ver_wall_hit_x;
	data->rays[id].wall_hit_y = (r->hor_dist < r->ver_dist) ? r->hor_wall_hit_y : r->ver_wall_hit_y;
	data->rays[id].is_ver = (r->ver_dist < r->hor_dist) ? 1 : 0;
	data->rays[id].is_up = r->is_up;
	data->rays[id].is_down = r->is_down;
	data->rays[id].is_left = r->is_left;
	data->rays[id].is_right = r->is_right;
}

void	ft_hor_loop(t_vars *data, t_cast *r)
{
	while (r->next_touch_hor_x >= 0
		&& r->next_touch_hor_x <= data->data.grid_width
		&& r->next_touch_hor_y >= 0
		&& r->next_touch_hor_y <= data->data.grid_height)
	{
		if (its_wall(data, r->next_touch_hor_x, r->next_touch_hor_y
				- (r->is_up ? 1 : 0)) == 1)
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
	while (r->next_touch_ver_x >= 0
		&& r->next_touch_ver_x <= data->data.grid_width
		&& r->next_touch_ver_y >= 0
		&& r->next_touch_ver_y <= data->data.grid_height)
	{
		if (its_wall(data, r->next_touch_ver_x - (r->is_left ? 1 : 0),
				r->next_touch_ver_y))
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

void	ft_cast_one_(t_vars *data, double angle, int id)
{
	t_cast	r;

	r.angle = ft_normalize(angle);
	ft_init_ray(data, &r);
	ft_intersection(data, &r, HOR);
	ft_steps(data, &r, HOR);
	ft_hor_loop(data, &r);
	// vertical intersection
	ft_intersection(data, &r, VER);
	ft_steps(data, &r, VER);
	ft_ver_loop(data, &r);
	ft_store(data, &r, id);
}

void	ft_cast_one(t_vars *data, double angle, int id)
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
			r.y_check -= 1;
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
	// Find the x-coordinate of the closest vertical grid intersection
	r.x_inters = floor(data->player.x / data->data.cub_size)
		* data->data.cub_size;
	if (r.is_right)
		r.x_inters += data->data.cub_size;
	// Find the y-coordinate of the closest vertical grid intersection
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
			r.x_check -= 1;
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
	double	ray_angle;

	ray_angle = data->player.rotation_angle - FOV / 2;
	ray_angle = ft_normalize(ray_angle);
	i = -1;
	// puts("--------");
	while (++i < data->data.num_rays)
	{
		ft_cast_one(data, ray_angle, i);
		ray_angle += (double)FOV / data->data.num_rays;
		ray_angle = ft_normalize(ray_angle);
		// printf("[%d]--<%d>--<%d>--<%d>--<%d>\n", i, data->rays[i].is_left,
		// 	data->rays[i].is_right, data->rays[i].is_up, data->rays[i].is_down);
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
