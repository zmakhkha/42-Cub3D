/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:02:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/26 17:05:44 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_debug(t_vars *data)
{
	puts("---- Deboguing ----");
	puts("Player info");
	printf("x : [%f] y : [%f]\n", data->player.x / data->data.cub_size, data->player.y / data->data.cub_size);
	puts("Ray info");
	printf("Angle : [%f], Distance : [%f], Type  :[%d]\n", data->rays[0].angle, data->rays[0].distance, data->rays[0].is_ver);
	printf("Left : [%d], Right : [%d], Up : [%d], Down : [%d]\n", data->rays[0].is_left, data->rays[0].is_right,  data->rays[0].is_up, data->rays[0].is_down);
	puts("----------");
}

void	ft_line_dda(t_vars *data, t_line l, int color)
{
	t_dda	d;
	int		i;

	d.dx = l.dx - l.ox;
	d.dy = l.dy - l.oy;
	d.step = fmax(fabs(d.dx), fabs(d.dy));
	d.x_inc = d.dx / d.step;
	d.y_inc = d.dy / d.step;
	i = -1;
	while (++i <= d.step)
	{
		l.ox = l.ox + d.x_inc;
		l.oy = l.oy + d.y_inc;
		my_mlx_pixel_put(&(data->img), round(l.ox), round(l.oy), color);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	ft_render_walls(t_vars *data)
{
	data->wall.i = -1;
	while (++data->wall.i < data->data.num_rays)
	{
		data->wall.dst_proj_plan = (data->data.win_width / 2) / tan(data->data.fov_angle / 2.0);
		data->wall.project_wall_height = (data->data.cub_size / data->rays[data->wall.i].distance) * data->wall.dst_proj_plan;
		data->wall.wall_height = (int) data->wall.project_wall_height;
		data->wall.top_pixel = (data->data.win_height / 2) - (data->wall.project_wall_height / 2);
		data->wall.bottom_pixel = (data->data.win_height / 2) + (data->wall.project_wall_height / 2);
		if (data->wall.top_pixel < 0)
			data->wall.top_pixel = 0;
		
		data->wall.line.ox = data->wall.i;
		data->wall.line.oy = data->wall.top_pixel;
		data->wall.line.dx = data->wall.i;
		data->wall.line.dy = data->wall.bottom_pixel;
		
		// printf("oy : [%f] [%f]\n", data->wall.line.oy, data->wall.line.dy);

		ft_line_dda(data, data->wall.line, WHITE);
	}
}

void	ft_render(t_vars *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_render_map(data);
	// ft_render_player(data);
	// ft_render_rays(data);
	ft_render_walls(data);
	// ft_debug(data);
}

int	main(int n, char **v)
{
	t_vars	*data;

	data = malloc(sizeof(t_vars));
	if (!data)
		ft_exit("Allocation Error!!\n", 1);
	data->parse = parsing_main(n, v);
	ft_init(data);
	ft_render(data);
	ft_wait(data);
}
