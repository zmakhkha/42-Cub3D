/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:02:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/12 15:19:19 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_line(t_vars *data, t_line l)
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
		printf("-----<%f>-+-<%f>\n", l.ox, l.oy);
		my_mlx_pixel_put(&(data->img), round(l.ox), round(l.oy), WHITE);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	ft_update(t_vars *data)
{
	ft_main_map(data);
	ft_update_player(data);
	mlx_clear_window(data->mlx, data->win);
	ft_draw_player(data);
}

int	main(int n, char **v)
{
	t_vars	*data;

	(void)n;
	(void)v;
	data = malloc(sizeof(t_vars));
	if (!data)
		ft_exit("Allocation Error!!\n", 1);
	ft_init(data);
	ft_main_map(data);
	ft_main_player(data);
	ft_wait(data);
	mlx_loop(data->mlx);
}
