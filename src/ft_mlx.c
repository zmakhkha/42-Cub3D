/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:17:56 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/09 00:04:46 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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
	mlx_hook(data->win, ON_DESTROY, 1L << 0, destroy, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
}

void	ft_initiate_window(t_vars *data)
{
	data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, \
		&(data->img.bits_per_pixel), &(data->img.line_length), \
		&(data->img.endian));
}

void	ft_init(t_vars *data)
{
	(void)data;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_WIDTH, TITLE);
}
