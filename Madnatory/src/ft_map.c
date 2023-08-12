/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:04:28 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 15:08:43 by zmakhkha         ###   ########.fr       */
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
	t_mini	mini;

	mini.cols = 0;
	mini.rows = ft_strlen2d(data->parse->map);
	mini.i = -1;
	while (++mini.i < mini.rows)
	{
		mini.curr_cols = ft_strlen(data->parse->map[mini.i]);
		if (mini.curr_cols > mini.cols)
			mini.cols = mini.curr_cols;
	}
	data->map = ft_calloc(mini.cols + 1, sizeof(char *));
	mini.i = -1;
	while (++mini.i < mini.cols)
	{
		data->map[mini.i] = ft_calloc((mini.rows + 1), sizeof(char));
	}
	mini.i = -1;
	while (++mini.i < mini.rows)
	{
		mini.curr_cols = ft_strlen(data->parse->map[mini.i]);
		mini.j = -1;
		while (++mini.j < mini.curr_cols)
			data->map[mini.j][mini.i] = data->parse->map[mini.i][mini.j];
	}
}
