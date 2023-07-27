/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:04:28 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/26 14:55:27 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	ft_strlen2d(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

void	ft_init_map(t_vars *data)
{
	int	i;
	int	j;
	int	rows;
	int	cols;
	int	curr_cols;

	cols = 0;
	rows = ft_strlen2d(data->parse->map);
	i = -1;
	while (++i < rows)
	{
		curr_cols = ft_strlen(data->parse->map[i]);
		if (curr_cols > cols)
			cols = curr_cols;
	}
	data->map = ft_calloc(cols + 1, sizeof(char *));
	i = -1;
	while (++i < cols)
	{
		data->map[i] = ft_calloc((rows + 1), sizeof(char));
	}
	i = -1;
	while (++i < rows)
	{
		curr_cols = ft_strlen(data->parse->map[i]);
		j = -1;
		while (++j < curr_cols)
			data->map[j][i] = data->parse->map[i][j];
	}
}
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
