/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:32:24 by edraidry          #+#    #+#             */
/*   Updated: 2023/08/13 19:55:37 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/header.h"



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
	ft_error("invalid elements in the file");
	return (0);
}

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



void	ft_chech_duplication(t_parse *content, int type)
{
	if (type == 1 && content->no)//no
		ft_error("north texture is duplicated");
	else if (type == 2 && content->ea)//ea
		ft_error("east texture is duplicated");
	else if (type == 3 && content->so)//so
		ft_error("south texture is duplicated");
	else if (type == 4 && content->we)//we
		ft_error("weast texture is duplicated");
	else if (type == 5 && content->ff)//f
		ft_error("floor is duplicated");
	else if (type == 6 && content->cc)//c
		ft_error("ciel is duplicated");
}

void	ft_chech_missing(t_parse *content)
{
	if (!content->no)//no
		ft_error("north texture not found");
	else if (!content->ea)//ea
		ft_error("east texture not found");
	else if (!content->so)//so
		ft_error("south texture not found");
	else if (!content->we)//we
		ft_error("weast texture not found");
	else if (!content->ff)//f
		ft_error("floor not found");
	else if (!content->cc)//c
		ft_error("ciel not found");
}


void	ft_set_type(t_parse *content, char *line, int index)
{
	int		type;
	char	*path;
	static int count = 0;
	
	type = ft_is_type(line);
	ft_chech_duplication(content, type);
	path = ft_get_type(line);
	if (type == 1)//no
		content->no = path;
	else if (type == 2)//ea
		content->ea = path;
	else if (type == 3)//so
		content->so = path;
	else if (type == 4)//we
		content->we = path;
	else if (type == 5)//f
	{
		check_f(path, content, 5);
	}
	else if (type == 6)//c
		check_f(path, content, 6);//	
	if (type != 7)
		++count;
	if (count == 6)
		content->start = index + 1;
}

t_parse	*ft_get_all_content(char **lines)
{
	int	i;
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
	// free_byte(lines);
	return (&content);
}