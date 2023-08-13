/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:57:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/13 18:39:53 by zmakhkha         ###   ########.fr       */
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
		data->player.rotation_angle = 0;
	else if (c == 'S')
		data->player.rotation_angle = M_PI / 2;
	else if (c == 'W')
		data->player.rotation_angle = M_PI;
	else if (c == 'N')
		data->player.rotation_angle = 1.5 * M_PI;
}

void	ft_spawn(t_vars *data)
{
	int		rows;
	int		i;
	int		j;
	char	c;

	c = 0;
	rows = ft_strlen2d(data->parse->map);
	i = -1;
	j = 0;
	while (++i < rows)
	{
		if (ft_strchr(data->map[i], 'S') || ft_strchr(data->map[i], 'N')
			|| ft_strchr(data->map[i], 'E') || ft_strchr(data->map[i], 'W'))
		{
			j = 0;
			while (!ft_isalpha(data->map[i][j]))
				j++;
			c = data->map[i][j];
			break ;
		}
	}
	data->player.x = i * data->data.cub_size + data->data.cub_size / 2;
	data->player.y = j * data->data.cub_size + data->data.cub_size / 2;
	ft_player_angle(data, data->map[i][j]);
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
	new_y = data->player.y + move_step * sin(data->player.rotation_angle);
	new_x = data->player.x + move_step * cos(data->player.rotation_angle);
	if (!its_wall(data, new_x, new_y) && !its_wall(data, new_x +8, new_y+8) \
	&& !its_wall(data, new_x -8, new_y-8)
	)
	{
			data->player.x = new_x;
			data->player.y = new_y;
		// }
	}
}
