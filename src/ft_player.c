/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:57:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/09 18:46:32 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_init_player(t_vars *data)
{
	data->player.x = data->data.grid_width / 2;
	data->player.y = data->data.grid_height / 2;
	data->player.move_speed = 2.0;
	data->player.rotation_angle = M_PI / 2;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_speed = 2.0 * M_PI / 180;
}

void	ft_update_player(t_vars *data)
{
	(void)data;
}

void	ft_render_player(t_vars *data)
{
	ft_update_player(data);
}

void	ft_main_player(t_vars *data)
{
	ft_init_player(data);
}
