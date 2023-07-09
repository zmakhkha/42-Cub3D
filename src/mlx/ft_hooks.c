/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:28:52 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/09 18:11:09 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

int	key_pressed(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == ARROW_LEFT)
	{
		puts("Leeft pressed");
	}
	if (keycode == ARROW_RIGHT)
	{
		puts("Rigght pressed");
	}
	if (keycode == ARROW_UP)
	{
		puts("Upp pressed");
	}
	if (keycode == ARROW_DOWN)
	{
		puts("DOOWn pressed");
	}
	return (0);
}

int	key_released(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == ARROW_LEFT)
	{
		puts("Leeeft released");
	}
	if (keycode == ARROW_RIGHT)
	{
		puts("Rigght released");
	}
	if (keycode == ARROW_UP)
	{
		puts("Upp released");
	}
	if (keycode == ARROW_DOWN)
	{
		puts("DOOWn released");
	}
	return (0);
}
