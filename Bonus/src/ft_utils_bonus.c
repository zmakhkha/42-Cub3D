/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:32:41 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 19:59:43 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Madnatory/headers/header.h"

void	ft_print_map(t_vars *data)
{
	int	i;
	int	j;

	puts("Printing the map");
	i = -1;
	while (++i < ft_strlen2d(data->map))
	{
		j = -1;
		while (++j < ft_strlen(data->map[i]))
		{
			printf("[%c]", data->map[i][j]);
		}
		puts("\n");
	}
	puts("################");
}

int	ft_render_bonus(t_vars *data)
{
	my_mlx_clear_window(data);
	ft_render_player(data);
	ft_render_rays(data);
	ft_bg(data);
	ft_render_walls(data);
	mlx_put_image_to_window(&(data->img), data->win, data->img.img, 0, 0);
	return (0);
}