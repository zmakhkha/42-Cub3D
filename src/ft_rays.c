/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:51:10 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/12 18:27:15 by zmakhkha         ###   ########.fr       */
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

double	ft_distance(int x1, int x2, int y1, int y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	ft_cast_one_(void)
{
}

void	ft_cast_one_vert(t_vars *data, double ray_ang, int i)
{
	t_ray	ray;

	ray.angle = ft_normalize(ray_ang);
	ray.is_down = ray.angle > 0 && ray.angle < M_PI;
	ray.is_up = !ray.is_up;
	ray.is_right = ray.angle < M_PI / 2 || ray.angle > 3 * M_PI / 2;
	ray.is_left = !ray.is_right;
	ray.is_ver_hit = 0;
	ray.ver_wall_x = 0;
	ray.ver_wall_y = 0;
	ray.h_wall_cont = 0;
	// find x
	ray.x_inter = floor(data->player.x / data->data.cub_size)
		* data->data.cub_size;
	if (ray.is_right)
		ray.x_inter += ray.x_inter - data->player.y;
	ray.y_inter = data->player.y + (ray.x_inter - data->player.x)
		/ tan(ray_ang);
	ray.x_step = data->data.cub_size;
	if (ray.is_left)
		ray.x_step *= -1;
	ray.y_step = data->data.cub_size / tan(ray_ang);
	if (ray.is_up && ray.x_step > 0)
		ray.x_step *= -1;
	if (ray.is_down && ray.x_step < 0)
		ray.x_step *= -1;
	ray.next_vx = ray.x_inter;
	ray.next_vy = ray.y_inter;
	while (ray.next_vx >= 0 && ray.next_vy <= WIDTH && ray.next_vy >= 0
		&& ray.next_vx <= HEIGHT)
	{
		if (ray.is_left)
			ray.x_check += -1;
		ray.y_check += ray.next_vy;
		if (its_wall(ray.x_check, ray.y_check))
		{
			ray.ver_wall_x = ray.next_vx;
			ray.ver_wall_y = ray.next_vy;
			ray.h_wall_cont = data->map[(int)floor(ray.x_check
				/ data->data.cub_size)][(int)floor(ray.y_check
				/ data->data.cub_size)];
			ray.is_ver_hit = 1;
			break ;
		}
		else
		{
			ray.next_vx = ray.x_step;
			ray.next_vy = ray.y_step;
		}
	}
}
void	ft_cast_one_hor(t_vars *data, double ray_ang, int i)
{
	t_ray	ray;

	ray.angle = ft_normalize(ray_ang);
	ray.is_down = ray.angle > 0 && ray.angle < M_PI;
	ray.is_up = !ray.is_up;
	ray.is_right = ray.angle < M_PI / 2 || ray.angle > 3 * M_PI / 2;
	ray.is_left = !ray.is_right;
	ray.is_hor_hit = 0;
	ray.hor_wall_x = 0;
	ray.hor_wall_y = 0;
	ray.h_wall_cont = 0;
	ray.y_inter = floor(data->player.y / data->data.cub_size)
		* data->data.cub_size;
	if (ray.is_down)
		ray.y_inter += ray.y_inter - data->player.y;
	ray.x_inter = data->player.x + (ray.y_inter - data->player.y)
		/ tan(ray_ang);
	ray.y_step = data->data.cub_size;
	if (ray.is_up)
		ray.y_step *= -1;
	ray.x_step = data->data.cub_size / tan(ray_ang);
	if (ray.is_left && ray.x_step > 0)
		ray.x_step *= -1;
	if (ray.is_right && ray.x_step < 0)
		ray.x_step *= -1;
	ray.next_hx = ray.x_inter;
	ray.next_hy = ray.y_inter;
	while (ray.next_hx >= 0 && ray.next_hy <= WIDTH && ray.next_hy >= 0
		&& ray.next_hx <= HEIGHT)
	{
		ray.x_check = ray.next_hx;
		if (ray.is_up)
			ray.y_check += -1;
		if (its_wall(ray.x_check, ray.y_check))
		{
			ray.hor_wall_x = ray.next_hx;
			ray.hor_wall_y = ray.next_hy;
			ray.h_wall_cont = data->map[(int)floor(ray.x_check
				/ data->data.cub_size)][(int)floor(ray.y_check
				/ data->data.cub_size)];
			ray.is_hor_hit = 1;
			break ;
		}
		else
		{
			ray.next_hx = ray.x_step;
			ray.next_hy = ray.y_step;
		}
	}
}

void	ft_cast_all_rays(t_vars *data)
{
	int i;
	double ray_angle;

	ray_angle = data->player.rotation_angle - (FOV / 2);
	i = -1;
	while (++i < data->data.num_rays)
		ft_cast_one(ray_angle, i);
}