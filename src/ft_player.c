/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:57:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/12 15:20:22 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	its_wall(t_vars *data, double x, double y)
{
	int	f_x;
	int	f_y;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return (1);
	f_x = floor(x / data->data.cub_size);
	f_y = floor(y / data->data.cub_size);
	printf("---+[%d][%d][%d]+---\n", f_x, f_y, data->map[f_x][f_y]);
	return (data->map[f_x][f_y] == 1);
}

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
	data->player.move_speed = 3.0;
	data->player.rotation_angle = M_PI / 2;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_speed = data->player.move_speed * M_PI / 180;
}

void	ft_update_player(t_vars *data)
{
	double	move_step;
	double	new_x;
	double	new_y;

	data->player.rotation_angle += data->player.turn_direction
		* data->player.rotation_speed;
	move_step = data->player.walk_direction * data->player.move_speed;
	new_y = data->player.y + move_step * sin(data->player.rotation_angle);
	new_x = data->player.x + move_step * cos(data->player.rotation_angle);
	if (!its_wall(data, new_x, new_y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
	else
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
