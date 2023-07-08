/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:04:28 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/09 00:02:58 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_init_map(t_vars *data, int **map)
{
	int	i;

	(void)map;
	data->map = malloc(8 * sizeof(int *));
	i = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			data->map[i][j] = i % 8 + 1;
		}
	}
}
