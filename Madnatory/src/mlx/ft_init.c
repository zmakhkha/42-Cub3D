/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:08:13 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/15 17:44:01 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

void	ft_validate(t_vars *data)
{
	if ((WIDTH < 256 || WIDTH > 5120) || (HEIGHT < 256 || HEIGHT > 2880))
	{
		free(data);
		ft_exit("Size Window Error !!\n", 1);
	}
}

int	ft_map_size(char **map, int i)
{
	int	a;
	int	b;
	int	max;
	int	len;

	max = 0;
	len = 0;
	a = ft_strlen2d(map);
	if (i == ROWS)
		return (a);
	else if (i == COLS)
	{
		b = -1;
		while (++b < a)
		{
			if ((int)ft_strlen(map[b]) > max)
				max = ft_strlen(map[b]);
		}
		return (max);
	}
	return (-1);
}

void	ft_init_shared(t_vars *data)
{
	data->data.win_width = WIDTH;
	data->data.win_height = HEIGHT;
	data->data.cub_size = TILE_SIZE;
	data->data.grid_rows = ft_map_size(data->parse->map, ROWS);
	data->data.grid_cols = ft_map_size(data->parse->map, COLS);
	data->data.grid_width = data->data.cub_size * data->data.grid_cols;
	data->data.grid_height = data->data.cub_size * data->data.grid_rows;
	data->data.fov_angle = FOV_DEG * (M_PI / 180);
	data->data.half_fov = data->data.fov_angle / 2;
	data->data.wall_stripe_width = 1;
	data->data.num_rays = data->data.win_width / data->data.wall_stripe_width;
}

// init the mlx stuff
void	ft_init(t_vars *data)
{
	ft_init_shared(data);
	data->mlx = mlx_init();
	ft_validate(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	ft_initiate_window(data);
	ft_init_map(data);
	ft_init_player(data);
	data->rays = malloc(data->data.num_rays * sizeof(t_ray));
	if (!data->rays)
		ft_exit("Allocation error !!", 1);
}

void	ft_initiate_window(t_vars *data)
{
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, \
		&(data->img.bits_per_pixel), &(data->img.line_length), \
		&(data->img.endian));
}
