/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:11:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/09 16:02:15 by zmakhkha         ###   ########.fr       */
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
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, rec.x, rec.y);
}

void	ft_render(t_vars *data)
{
	int		i;
	int		j;
	t_rect	rec;

	i = -1;
	while (++i < data->data.grid_rows)
	{
		j = -1;
		while (++j < data->data.grid_cols)
		{
			if (data->map[i][j])
				rec.fill = RED;
			else
				rec.fill = WHITE;
			rec.x = i * data->data.cub_size;
			rec.y = j * data->data.cub_size;
			rec.len = data->data.cub_size;
			printf("[%d][%d] ", rec.x, rec.y);
			ft_rectangle(data, rec);
		}
		printf("\n");
	}
}
