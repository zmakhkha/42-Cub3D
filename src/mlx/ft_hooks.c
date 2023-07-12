/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:28:52 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/12 11:30:45 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

int	key_pressed(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == ON_ESC)
		destroy(vars);
	if (keycode == ARROW_LEFT)
	{
		vars->player.turn_direction = -1;
	}
	if (keycode == ARROW_RIGHT)
	{
		vars->player.turn_direction = 1;
	}
	if (keycode == ARROW_UP)
	{
		vars->player.walk_direction = 1;
	}
	if (keycode == ARROW_DOWN)
	{
		vars->player.walk_direction = -1;
	}
	ft_update(vars);
	return (0);
}

int	key_released(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == ARROW_LEFT)
	{
		vars->player.turn_direction = 0;
	}
	if (keycode == ARROW_RIGHT)
	{
		vars->player.turn_direction = 0;
	}
	if (keycode == ARROW_UP)
	{
		vars->player.walk_direction = 0;
	}
	if (keycode == ARROW_DOWN)
	{
		vars->player.walk_direction = 0;
	}
	ft_update(vars);
	return (0);
}
