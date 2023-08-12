/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:12:28 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 18:12:26 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft__select_texture(t_vars *data)
{
	if (data->rays[data->wall.i].is_left \
		&& data->rays[data->wall.i].is_ver)
	{
		data->wall.hight = data->wall.hight_ea;
		data->wall.width = data->wall.width_ea;
		data->wall.buffer = data->wall.texture_ea;
	}
	else if (data->rays[data->wall.i].is_right \
		&& data->rays[data->wall.i].is_ver)
	{
		data->wall.hight = data->wall.hight_so;
		data->wall.width = data->wall.width_so;
		data->wall.buffer = data->wall.texture_so;
	}
}

void	ft_select_texture(t_vars *data)
{
	if (data->rays[data->wall.i].is_up && !data->rays[data->wall.i].is_ver)
	{
		data->wall.hight = data->wall.hight_no;
		data->wall.width = data->wall.width_no;
		data->wall.buffer = data->wall.texture_no;
	}
	else if (data->rays[data->wall.i].is_down \
		&& !data->rays[data->wall.i].is_ver)
	{
		data->wall.hight = data->wall.hight_we;
		data->wall.width = data->wall.width_we;
		data->wall.buffer = data->wall.texture_we;
	}
	else
		ft__select_texture(data);
}

void	ft_draw_wall(t_vars *data)
{
	int	j;
	int	xp;
	int	yp;

	j = 0;
	if (!data->rays[data->wall.i].is_ver)
		xp = data->wall.width * fmod(data->rays[data->wall.i].wall_hit_x, \
			TILE_SIZE) / TILE_SIZE; 
	else
		xp = data->wall.width * fmod(data->rays[data->wall.i].wall_hit_y, \
			TILE_SIZE) / TILE_SIZE;
	while (j < data->wall.project_wall_height)
	{
		yp = (j * data->wall.hight) / data->wall.project_wall_height;
		if (0 <= data->wall.line.ox \
			&& data->wall.line.ox <= data->data.win_height && 0 <= (int)(j \
				+ (HEIGHT / 2) - (data->wall.project_wall_height / 2)) \
			&& (int)(j + (HEIGHT / 2) - (data->wall.project_wall_height \
					/ 2)) <= data->data.win_height)
			my_mlx_pixel_put(&data->img, data->wall.line.ox, (int)(j + (HEIGHT \
						/ 2) - (data->wall.project_wall_height / 2)), \
				data->wall.buffer[(yp * data->wall.width) + xp]);
		j++;
	}
}

void	ft_render_walls(t_vars *data)
{
	data->wall.i = -1;
	while (++data->wall.i < data->data.num_rays)
	{
		ft_empty_wall(data);
		ft_select_texture(data);
		ft_draw_wall(data);
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
