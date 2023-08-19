/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:23:01 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/14 15:34:48 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_map_is_valid(t_parse *content)
{
	int		i;
	int		o;
	char	*str;

	i = 0;
	while (content->map[i])
	{
		o = 0;
		str = content->map[i];
		while (str[o])
		{
			if (str[o] != '0' && str[o] != '1' && str[o] != ' ' && str[o] != 'N'
				&& str[o] != 'E' && str[o] != 'S' && str[o] != 'W')
				ft_error("invalid character found in the map");
			++o;
		}
		++i;
	}
}

void	ft_check_player_exists(t_parse *content)
{
	int		i;
	int		o;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	while (content->map[i])
	{
		o = 0;
		str = content->map[i];
		while (str[o])
		{
			if (str[o] == 'N' || str[o] == 'E' || str[o] == 'S'
				|| str[o] == 'W')
				++count;
			++o;
		}
		++i;
	}
	if (count != 1)
		ft_error("should have only one player in  the map");
}
