/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:59:03 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/14 15:36:04 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

char	*ft_get_type(char *line)
{
	int		i;
	int		o;
	char	*path;

	i = 0;
	while (line[i] == ' ')
		++i;
	while (line[i] != ' ')
		++i;
	while (line[i] == ' ')
		++i;
	o = ft_strlen(line) - 1;
	while (line[o] == ' ' && o != i)
		--o;
	line[o + 1] = '\0';
	path = ft_strdup(&line[i]);
	if (!path)
		ft_error("malloc fail");
	return (path);
}
