/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:02:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 20:14:15 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Madnatory/headers/header.h"
int	mouse_move(int x, int y, t_vars *data)
{
	(void)data;
	if (0 <= x && x <= data->data.win_width && 0 <= y && y <= data->data.win_height)
	{
		if (x < (data->data.win_width / 2) - 150)
			data->player.turn_direction = -1;
		else if (x > (data->data.win_width / 2) + 150)
			data->player.turn_direction = 1;
		else
			data->player.turn_direction = 0;
	}
}

void	ft_wait_bonus(t_vars *data)
{
	mlx_hook(data->win, 2, 0, key_pressed, data);
	mlx_hook(data->win, 3, 0, key_released, data);
	mlx_hook(data -> win, M_NOTIFY, 1L << 6, mouse_move, data);
	mlx_hook(data->win, ON_DESTROY, 1L << 0, destroy, data);
	mlx_loop_hook(data->mlx, ft_render, (void *)data);
	mlx_loop(data->mlx);
}


int	main(int n, char **v)
{
	t_vars	*data;
	data = malloc(sizeof(t_vars));
	if (!data)
		ft_exit("Allocation Error!!\n", 1);
	data->parse = parsing_main(n, v);
	ft_init(data);
	load_images(data);
	ft_render(data);
	ft_wait_bonus(data);
}