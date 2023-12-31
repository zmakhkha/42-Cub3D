/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:32:24 by edraidry          #+#    #+#             */
/*   Updated: 2023/08/19 08:07:10 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	ft_is_type(char *line)
{
	int	i;

	if (line[0] == '\0')
		return (7);
	i = 0;
	while (line[i] == ' ')
		++i;
	if (!ft_strncmp(&line[i], "NO ", 3))
		return (1);
	if (!ft_strncmp(&line[i], "EA ", 3))
		return (2);
	if (!ft_strncmp(&line[i], "SO ", 3))
		return (3);
	if (!ft_strncmp(&line[i], "WE ", 3))
		return (4);
	if (!ft_strncmp(&line[i], "F ", 2))
		return (5);
	if (!ft_strncmp(&line[i], "C ", 2))
		return (6);
	ft_error("Error : invalid elements in the file");
	return (0);
}

void	ft_chech_duplication(t_parse *content, int type)
{
	if (type == 1 && content->no)
		ft_error("Error : north texture is duplicated");
	else if (type == 2 && content->ea)
		ft_error("Error : east texture is duplicated");
	else if (type == 3 && content->so)
		ft_error("Error : south texture is duplicated");
	else if (type == 4 && content->we)
		ft_error("Error : weast texture is duplicated");
	else if (type == 5 && content->ff)
		ft_error("Error : floor is duplicated");
	else if (type == 6 && content->cc)
		ft_error("Error : ciel is duplicated");
}

void	ft_chech_missing(t_parse *content)
{
	if (!content->no)
		ft_error("Error : north texture not found");
	else if (!content->ea)
		ft_error("Error : east texture not found");
	else if (!content->so)
		ft_error("Error : south texture not found");
	else if (!content->we)
		ft_error("Error : weast texture not found");
	else if (content->ff < 0)
		ft_error("Error : floor not found");
	else if (content->cc < 0)
		ft_error("Error : ciel not found");
}

void	ft_set_type(t_parse *content, char *line, int index)
{
	int			type;
	char		*path;
	static int	count = 0;

	type = ft_is_type(line);
	ft_chech_duplication(content, type);
	path = ft_get_type(line);
	if (type == 1)
		content->no = path;
	else if (type == 2)
		content->ea = path;
	else if (type == 3)
		content->so = path;
	else if (type == 4)
		content->we = path;
	else if (type == 5)
		check_f(path, content, 5);
	else if (type == 6)
		check_f(path, content, 6);
	if (type != 7)
		++count;
	if (count == 6)
		content->start = index + 1;
}

t_parse	*ft_get_all_content(char **lines)
{
	int				i;
	static t_parse	content;

	i = 0;
	while (lines[i] && content.start == 0)
	{
		ft_is_type(lines[i]);
		if (lines[i][0])
			ft_set_type(&content, lines[i], i);
		++i;
	}
	ft_chech_missing(&content);
	return (&content);
}
