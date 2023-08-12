/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:57:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 12:45:36 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	its_wall(t_vars *data, double x, double y)
{
	int	f_x;
	int	f_y;

	if (x < 0 || y < 0)
		return (1);
	f_x = floor(x / data->data.cub_size);
	f_y = floor(y / data->data.cub_size);
	if (data->map && data->map[f_x] && data->map[f_x][f_y])
		return (data->map[f_x][f_y] == '1');
	return (1);
}

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
	int		cols;
	int		i;
	int		j;
	char	c;

	c = 0;
	rows = ft_strlen2d(data->parse->map);
	i = -1;
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
	data->player.move_speed = 50;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.rotation_speed = 0.0005 * data->player.move_speed;
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
	if (!its_wall(data, new_x, new_y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}
