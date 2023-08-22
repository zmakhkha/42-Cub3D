/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main__parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:27:50 by edraidry          #+#    #+#             */
/*   Updated: 2023/08/22 17:28:12 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	ft_get_map_index(t_parse *content, char **lines)
{
	int	start;

	start = content->start;
	while (lines[start] && lines[start][0] == '\0')
		++start;
	content->start = start;
}

int	ft_max_line(t_parse *content, char **lines)
{
	int	start;
	int	max;

	start = content->start;
	max = 0;
	while (lines[start])
	{
		if ((int)ft_strlen(lines[start]) > max)
			max = ft_strlen(lines[start]);
		++start;
	}
	return (max);
}
