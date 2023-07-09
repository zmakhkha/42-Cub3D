/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:04:28 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/09 18:27:13 by zmakhkha         ###   ########.fr       */
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
			if (i == j)
				data->map[i][j] = 1;
			else
				data->map[i][j] = 0;
		}
	}
}

void	ft_main_map(t_vars *data)
{
	ft_init_map(data);
	ft_render(data);
}
