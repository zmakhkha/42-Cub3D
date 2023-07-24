/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:08:13 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/13 17:56:32 by zmakhkha         ###   ########.fr       */
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

void	ft_init_shared(t_vars *data)
{
	data->data.cub_size = TILE_SIZE;
	data->data.grid_rows = MAP_NUM_ROWS;
	data->data.grid_cols = MAP_NUM_COLS;
	data->data.grid_width = data->data.cub_size * data->data.grid_cols;
	data->data.grid_height = data->data.cub_size * data->data.grid_rows;
	data->data.fov_angle = 60 * (M_PI / 180);
	data->data.wall_stripe_width = 20;
	data->data.num_rays = data->data.grid_width / data->data.wall_stripe_width;
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
	data->img.addr = mlx_get_data_addr(data->img.img,
		&(data->img.bits_per_pixel), &(data->img.line_length),
		&(data->img.endian));
}
