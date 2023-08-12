/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:28:52 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 14:49:23 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

// W = 13
// S = 1
// A =  0
// D =  2
int	key_pressed(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == ON_ESC)
		destroy(vars);
	if (keycode == ARROW_LEFT || keycode == 0)
	{
		vars->player.turn_direction = -1;
	}
	if (keycode == ARROW_RIGHT || keycode == 2)
	{
		vars->player.turn_direction = 1;
	}
	if (keycode == ARROW_UP || keycode == 13)
	{
		vars->player.walk_direction = 1;
	}
	if (keycode == ARROW_DOWN || keycode == 1)
	{
		vars->player.walk_direction = -1;
	}
	ft_render(vars);
	return (0);
}

int	key_released(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == ARROW_LEFT || keycode == 0)
	{
		vars->player.turn_direction = 0;
	}
	if (keycode == ARROW_RIGHT || keycode == 2)
	{
		vars->player.turn_direction = 0;
	}
	if (keycode == ARROW_UP || keycode == 13)
	{
		vars->player.walk_direction = 0;
	}
	if (keycode == ARROW_DOWN || keycode == 1)
	{
		vars->player.walk_direction = 0;
	}
	ft_render(vars);
	return (0);
}
