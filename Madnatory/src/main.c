/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:02:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/05 08:34:40 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

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
		if (l.ox >= 0 && l.ox <= WIDTH && l.oy >=0 && l.oy <= HEIGHT)
			my_mlx_pixel_put(&data->img, round(l.ox), round(l.oy), color);
	}
}

// 11.wall projection
void	ft_render_walls(t_vars *data)
{
	data->wall.i = -1;
	while (++data->wall.i < data->data.num_rays)
	{
		data->wall.cr_dist = data->rays[data->wall.i].distance
			* cos(data->rays[data->wall.i].angle - data->player.rotation_angle);
		data->wall.dst_proj_plan = (data->data.win_width / 2)
			/ tan(data->data.fov_angle / 2.0);
		data->wall.project_wall_height = (data->data.cub_size
			/ data->wall.cr_dist) * data->wall.dst_proj_plan;
		data->wall.wall_height = (int)data->wall.project_wall_height;
		data->wall.top_pixel = (data->data.win_height / 2)
			- (data->wall.project_wall_height / 2);
		data->wall.bottom_pixel = (data->data.win_height / 2)
			+ (data->wall.project_wall_height / 2);
		if (data->wall.top_pixel < 0)
			data->wall.top_pixel = 0;
		if (data->wall.bottom_pixel > data->data.win_height)
			data->wall.bottom_pixel = data->data.win_height;

		data->wall.line.ox = data->wall.i;
		data->wall.line.oy = data->wall.top_pixel;
		data->wall.line.dx = data->wall.i;
		data->wall.line.dy = data->wall.bottom_pixel;
		ft_line_dda(data, data->wall.line, RED);
	}
}

void	ft_bg(t_vars *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->data.win_height / 2)
	{
		j = -1;
		while (++j < data->data.win_width)
		{
			my_mlx_pixel_put(&data->img, j, i, data->parse->ff);
		}
	}
	i = data->data.win_height / 2;
	while (++i < data->data.win_height)
	{
		j = -1;
		while (++j < data->data.win_width)
		{
			my_mlx_pixel_put(&data->img, j, i, data->parse->cc);
		}
	}
}

int	ft_render(t_vars *data)
{
	my_mlx_clear_window(data);
	ft_render_player(data);
	ft_render_rays(data);
	ft_bg(data);
	ft_render_walls(data);
	mlx_put_image_to_window(&(data->img), data->win, data->img.img, 0, 0);
	return (0);
}

void	ft_resolution()
{
		if ((WIDTH < 250 || WIDTH > 5000) || (HEIGHT < 250 || HEIGHT > 2500))
		{
			printf("Resolution error !!");
			exit(1);
		}
}

int	main(int n, char **v)
{
	t_vars	*data;

	// ft_resolution();
	data = malloc(sizeof(t_vars));
	if (!data)
		ft_exit("Allocation Error!!\n", 1);
	data->parse = parsing_main(n, v);
	ft_init(data);
	ft_render(data);
	ft_wait(data);
}
