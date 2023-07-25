/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:04:28 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/25 18:25:55 by zmakhkha         ###   ########.fr       */
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

	rows = ft_strlen2d(data->parse->map);
	data->map = ft_calloc(sizeof(char *), 1 + rows);
	i = -1;
	while (++i < rows)
	{
		cols = ft_strlen(ft_strtrim(data->parse->map[i], " "));
		data->map[i] = ft_calloc(cols + 1, sizeof(char));
		j = -1;
		while (++j < cols)
			data->map[i][j] = data->parse->map[i][j];
	}
}

void	ft_print_map(t_vars *data)
{
	int	i;
	int	j;

	(void)data;
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
}
