/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:02:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 16:05:27 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

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

void select_image(t_vars *data)
{
	int w;
	int h;
	void *xpm = mlx_xpm_file_to_image(data->mlx, data->parse->ea, &data->width_we, &data->hight_we);
	data->texture_we = (int *)mlx_get_data_addr(xpm, &w, &w, &h);
	

	xpm = mlx_xpm_file_to_image(data->mlx, data->parse->no, &data->width_ea, &data->hight_ea);
	data->texture_ea = (int *)mlx_get_data_addr(xpm, &w, &w, &h);

	xpm = mlx_xpm_file_to_image(data->mlx, data->parse->so, &data->width_so, &data->hight_so);
	data->texture_so = (int *)mlx_get_data_addr(xpm, &w, &w, &h);
	

	xpm = mlx_xpm_file_to_image(data->mlx, data->parse->we, &data->width_no, &data->hight_no);
	data->texture_no = (int *)mlx_get_data_addr(xpm, &w, &w, &h);
	
}

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

	int *buffer;
	int hight;
	int width;
	

	if (data->rays[data->wall.i].is_up && !data->rays[data->wall.i].is_ver)
	{
		hight = data->hight_no;
		width = data->width_no;
		buffer = data->texture_no;
	}
	else if (data->rays[data->wall.i].is_down && !data->rays[data->wall.i].is_ver)
	{
		hight = data->hight_we;
		width = data->width_we;
		buffer = data->texture_we;
	}
	else if (data->rays[data->wall.i].is_left && data->rays[data->wall.i].is_ver)
	{
		hight = data->hight_ea;
		width = data->width_ea;
		buffer = data->texture_ea;
	}
	else if (data->rays[data->wall.i].is_right && data->rays[data->wall.i].is_ver)
	{
		hight = data->hight_so;
		width = data->width_so;
		buffer = data->texture_so;
	}


		int j = 0;
		int xp;

		if (!data->rays[data->wall.i].is_ver)
			xp = width * fmod(data->rays[data->wall.i].wall_hit_x, TILE_SIZE) / TILE_SIZE ; // fmod(data->rays[data->wall.i].wall_hit_x, TILE_SIZE) / TILE_SIZE  hadi nissba ka tkun mn [0 - 1]
		else
			xp = width * fmod(data->rays[data->wall.i].wall_hit_y, TILE_SIZE) / TILE_SIZE ;
		// if (!data->rays[data->wall.i].is_ver)
		// 	xp = fmod(data->rays[data->wall.i].wall_hit_x, width);
		// else
		// 	xp = fmod(data->rays[data->wall.i].wall_hit_y, width);
		// if(data->wall.project_wall_height >= HEIGHT)
		// {
		// 	float scale = 1000 / data->wall.project_wall_height;
    	// 	xp = (int)(xp * scale);
		// }		
		while (j < data->wall.project_wall_height)
		{
			int yp = (j * hight) / data->wall.project_wall_height;
			my_mlx_pixel_put(&data->img, data->wall.line.ox, j + (HEIGHT / 2) - (data->wall.project_wall_height / 2), buffer[(yp * width) +  xp]);
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
	// printf("[%f]\n", data->rays[]->distance);
	//ft_minimap(data);
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
	select_image(data);
	ft_render(data);
	ft_wait(data);
}
