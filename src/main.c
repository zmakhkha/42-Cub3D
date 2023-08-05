/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:02:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/03 22:27:01 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_mouse(t_vars *data, int x, int y)
{
	
}

void	ft_mini_grid(t_vars *data) // to protect with small window size
{
	t_mini	mini;
	t_rect	rec;

	mini.i = -1;
	mini.j = -1;
	while (++mini.i < 20)
	{
		while(++mini.j < 20)
		{
			rec.x = (int)floor(mini.i / MINI_CUB) * MINI_CUB;
			rec.y = (int)floor(mini.j / MINI_CUB) * MINI_CUB;
			if (rec.x == 0 || rec.y == 0)
			{
				rec.len = 10;
				rec.fill = RED;
				ft_rectangle(data, rec);
			}			
		}
	}
}

void	ft_minimap(t_vars *data)
{
	t_mini	mini;
	ft_mini_grid(data);
	// mini.x_player = (int)floor(data->player.x /data->data.cub_size);
	// mini.y_player = (int)floor(data->player.y /data->data.cub_size);
	// mini.x_start = mini.x_player - 1;
	// mini.x_end = mini.x_player + 1;
	// mini.y_start = mini.y_player - 1;
	// mini.y_end = mini.y_player + 1;
	// mini.l.ox = (mini.x_start + 100);
	// mini.l.oy = (mini.y_start +100);
	// mini.l.dx = (mini.x_start + 100) + 20 * cos(data->player.rotation_angle);
	// mini.l.dy = (mini.y_start +100) + 20 * sin(data->player.rotation_angle);
	
	// int		i;
	// int		j;
	// t_rect	rec;

	// i = mini.y_start - 1;
	// while (++i <= mini.y_end)
	// {
	// 	j = mini.x_start - 1;
	// 	while (++j <= mini.x_end)
	// 	{
	// 		if (data->map[i][j] == ' ')
	// 			continue ;
	// 		if (data->map[i][j] == '1')
	// 			rec.fill = BLACK;
	// 		else
	// 			rec.fill = WHITE;
	// 		rec.len = 100;
	// 		rec.x = (j - mini.x_start) * rec.len;
	// 		rec.y = (i - mini.y_start) * rec.len;
	// 		ft_rectangle(data, rec);
	// 	}
	// }
	// ft_line_dda(data, mini.l, RED);
}


void	ft_debug(t_vars *data)
{
	puts("---- Deboguing ----");
	puts("Player info");
	printf("x : [%f] y : [%f]\n", data->player.x / data->data.cub_size,
		data->player.y / data->data.cub_size);
	puts("Ray info");
	printf("Angle : [%f], Distance : [%f], Type  :[%d]\n", data->rays[0].angle,
		data->rays[0].distance, data->rays[0].is_ver);
	printf("Left : [%d], Right : [%d], Up : [%d], Down : [%d]\n",
		data->rays[0].is_left, data->rays[0].is_right, data->rays[0].is_up,
		data->rays[0].is_down);
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
		my_mlx_pixel_put(&data->img, round(l.ox), round(l.oy), color);
	}
}

// 11.wall projection
void	ft_render_walls(t_vars *data)
{
	data->wall.i = -1;
	int w;
	void *xpm = mlx_xpm_file_to_image(data->mlx, "texture/image2.xpm", &w, &w);
	int *coller_buffer = (int *)mlx_get_data_addr(xpm, &w, &w, &w);

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


		int j = 0;
		int xp;

		if (!data->rays[data->wall.i].is_ver)
			xp = fmod(data->rays[data->wall.i].wall_hit_x, data->data.cub_size);
		else
			xp = fmod(data->rays[data->wall.i].wall_hit_y, data->data.cub_size);
		
		while (j < data->wall.project_wall_height)
		{
			int yp = (j * data->data.cub_size) / data->wall.project_wall_height;
			my_mlx_pixel_put(&data->img, data->wall.line.ox, j + (HEIGHT / 2) - (data->wall.project_wall_height / 2), coller_buffer[(yp * data->data.cub_size) +  xp]);
			j++;
		}

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
	ft_minimap(data);
	mlx_put_image_to_window(&(data->img), data->win, data->img.img, 0, 0);
	return (0);
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
