/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:04:28 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/09 16:12:21 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_init_map(t_vars *data)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	rows = data->data.grid_rows;
	cols = data->data.grid_cols;
	data->map = malloc(rows * sizeof(int *));
	i = -1;
	while (++i < rows)
	{
		data->map[i] = malloc(cols * sizeof(int));
		j = -1;
		while (++j < cols)
		{
			data->map[i][j] = cols % 3;
		}
	}
}

void	ft_print_map(t_vars *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i)
	{
		j = -1;
		while (++j)
		{
			printf("[%d]", data->map[i][j]);
		}
		puts("\n");
	}
}

void	ft_main_map(t_vars *data)
{
	t_rect	rec;

	rec.x = 5;
	rec.y = 5;
	rec.len = 50;
	rec.fill = 0x00FF0000;
	ft_init_map(data);
	ft_print_map(data);
	ft_render(data);
	// ft_rectangle(data, rec);
}
