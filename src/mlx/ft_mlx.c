/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:17:56 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/24 11:19:23 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *data)
{
	if (keycode == ON_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data);
		data = NULL;
		ft_exit("Destroyed successfully !!", 0);
	}
	return (0);
}

int	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
	ft_exit("Destroyed successfully !!", 0);
	return (0);
}

void	ft_wait(t_vars *data)
{
	mlx_hook(data->win, 2, 0, key_pressed, data);
	mlx_hook(data->win, 3, 0, key_released, data);
	mlx_hook(data->win, ON_DESTROY, 1L << 0, destroy, data);
	mlx_loop_hook(data->mlx, ft_render, data);
	mlx_loop(data->mlx);
}
