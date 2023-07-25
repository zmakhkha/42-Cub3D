/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:11:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/25 18:19:53 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

void	ft_rectangle(t_vars *data, t_rect rec)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rec.len)
	{
		j = -1;
		while (++j < rec.len)
		{
			my_mlx_pixel_put(&data->img, rec.x + i, rec.y + j, rec.fill);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	ft_render_map(t_vars *data)
{
	int		i;
	int		j;
	t_rect	rec;

	i = -1;
	while (++i < ft_strlen2d(data->map))
	{
		j = -1;
		while (++j < ft_strlen(data->map[i]))
		{
			if (data->map[i][j] == '0')
				rec.fill = BLUE;
			else
				rec.fill = RED;
			rec.x = i * data->data.cub_size;
			rec.y = j * data->data.cub_size;
			rec.len = data->data.cub_size;
			ft_rectangle(data, rec);
		}
	}
}
