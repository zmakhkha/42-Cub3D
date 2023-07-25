/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:02:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/25 16:29:39 by zmakhkha         ###   ########.fr       */
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
		my_mlx_pixel_put(&(data->img), round(l.ox), round(l.oy), color);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	ft_render(t_vars *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_render_map(data);
	ft_render_player(data);
	ft_render_rays(data);
}

int	main(int n, char **v)
{
	t_vars	*data;

	data = malloc(sizeof(t_vars));
	if (!data)
		ft_exit("Allocation Error!!\n", 1);
	data->parse = parsing_main(n, v);
	ft_init(data);
	ft_render(data);
	ft_wait(data);
}
