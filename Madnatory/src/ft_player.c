/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:57:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/19 06:58:26 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_player_line(t_vars *data)
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
}

void	ft_player_angle(t_vars *data, char c)
{
	if (c == 'E')
		data->player.rotation_angle = 2 * M_PI;
	else if (c == 'S')
		data->player.rotation_angle = M_PI / 2;
	else if (c == 'W')
		data->player.rotation_angle = M_PI;
	else if (c == 'N')
		data->player.rotation_angle = 1.5 * M_PI;
}

void	ft_spawn(t_vars *data)
{
	int		i;
	int		j;
	char	c;

	c = 0;
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'S' || data->map[i][j] == 'N' \
			|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				c = data->map[i][j];
				data->player.x = i * data->data.cub_size + \
				data->data.cub_size / 2;
				data->player.y = j * data->data.cub_size + \
				data->data.cub_size / 2;
				ft_player_angle(data, data->map[i][j]);
				return ;
			}
		}
	}
}

void	ft_init_player(t_vars *data)
{
	ft_spawn(data);
	data->player.move_speed = 1.5;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_speed = data->player.move_speed * M_PI / 180;
}

void	ft_render_player(t_vars *data)
{
	double	move_step;
	double	new_x;
	double	new_y;

	data->player.rotation_angle += data->player.turn_direction
		* data->player.rotation_speed;
	move_step = data->player.walk_direction * data->player.move_speed;
	new_y = data->player.y + move_step * sin(data->player.rotation_angle \
		+ data->player.turn);
	new_x = data->player.x + move_step * cos(data->player.rotation_angle \
		+ data->player.turn);
	if (!its_wall(data, new_x, new_y) && !its_wall(data, data->player.x, new_y)
		&& !its_wall(data, new_x, data->player.y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}
