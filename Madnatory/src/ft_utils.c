/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:32:41 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/13 22:37:00 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_line_dda(t_vars *data, t_line l, int color)
{
	t_dda	d;
	int		i;

	d.dx = l.dx - l.ox;
	d.dy = l.dy - l.oy;
	d.step = fmax(fabs(d.dx), fabs(d.dy));
	d.x_inc = d.dx / d.step;
	d.y_inc = d.dy / d.step;
	i = -1;
	while (++i <= d.step)
	{
		l.ox = l.ox + d.x_inc;
		l.oy = l.oy + d.y_inc;
		if (l.ox >= 0 && l.ox <= WIDTH && l.oy >= 0 && l.oy <= HEIGHT)
			my_mlx_pixel_put(&data->img, round(l.ox), round(l.oy), color);
	}
}

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

int	ft_render(t_vars *data)
{
	my_mlx_clear_window(data);
	ft_render_player(data);
	ft_render_rays(data);
	ft_bg(data);
	ft_render_walls(data);
	mlx_put_image_to_window(&(data->img), data->win, data->img.img, 0, 0);
	return (0);
}

void	ft_exit(char *str, int status)
{
	write(1, str, ft_strlen(str));
	exit(status);
}
