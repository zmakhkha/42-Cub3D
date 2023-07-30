/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:17:56 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/28 19:55:33 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

void	my_mlx_clear_window(t_vars *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->data.win_width)
	{
		j = -1;
		while (++j < data->data.win_height)
			my_mlx_pixel_put(&data->img, i, j, BLACK);
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return;
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
	mlx_loop_hook(data->mlx, ft_render, (void *)data);
	mlx_loop(data->mlx);
}
