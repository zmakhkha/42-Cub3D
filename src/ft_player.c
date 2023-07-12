/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:57:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/12 14:35:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_draw_player(t_vars *data)
{
	t_rect	p;
	t_line	l;

	p.x = data->player.x;
	p.y = data->player.y;
	p.len = 10;
	p.fill = WHITE;
	l.ox = p.x;
	l.oy = p.y;
	l.dx = l.ox + cos(data->player.rotation_angle) * 20;
	l.dy = l.oy + sin(data->player.rotation_angle) * 20;
	// ft_rectangle(data, p);
	ft_line(data, l);
}

void	ft_init_player(t_vars *data)
{
	data->player.x = data->data.grid_width / 2;
	data->player.y = data->data.grid_height / 2;
	data->player.move_speed = 2.0;
	data->player.rotation_angle = M_PI / 2;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_speed = data->player.move_speed * M_PI / 180;
}

void	ft_update_player(t_vars *data)
{
	double	move_step;

	data->player.rotation_angle += data->player.turn_direction
		* data->player.rotation_speed;
	move_step = data->player.walk_direction * data->player.move_speed;
	data->player.y += move_step * sin(data->player.rotation_angle);
	data->player.x += move_step * cos(data->player.rotation_angle);
	printf("-----<%f>--<%f>-<%f>--\n", data->player.rotation_angle,
		data->player.x, data->player.y);
}

void	ft_render_player(t_vars *data)
{
	ft_update_player(data);
}

void	ft_main_player(t_vars *data)
{
	ft_init_player(data);
	ft_draw_player(data);
}
