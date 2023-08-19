/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:02:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/19 07:48:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	pl(char **map)
{
	int i;
	int j;
	i=-1;
	while(map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if (map[i][j] == 'N')
				printf("[%d][%d]\n", i, j);
		}
	}
}

int	_main(int n, char **v)
{
	t_vars	*data;

	data = malloc(sizeof(t_vars));
	if (!data)
		ft_exit("Allocation Error!!\n", 1);
	data->parse = parsing_main(n, v);
	pl(data->parse->map);
	ft_init(data);
	load_images(data);
	ft_render(data);
	ft_wait(data);
	return (0);
}

int	main(int n, char **v)
{
	_main(n, v);
}
