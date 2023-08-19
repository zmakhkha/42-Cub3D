/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:57:25 by edraidry          #+#    #+#             */
/*   Updated: 2023/08/19 08:05:48 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

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

void	ft_copy_map(t_parse *content, char **lines)
{
	int		start;
	int		max;
	char	*str;
	char	**tmp;

	max = ft_max_line(content, lines);
	start = content->start;
	while (lines[start])
	{
		if (lines[start][0] == '\0')
			ft_error("empty line found in the map");
		str = malloc(max + 1);
		if (!str)
			ft_error("malloc fail");
		ft_memset(str, ' ', max);
		str[max] = '\0';
		ft_memcpy(str, lines[start], ft_strlen(lines[start]));
		tmp = ft_realloc(content->map, str);
		free(content->map);
		content->map = tmp;
		++start;
	}
}

void	ft_is_valid_map(t_parse *cont)
{
	t_mini	m;

	m.rows = -1;
	while (cont->map[++m.rows])
	{
		m.cols = -1;
		m.str = cont->map[m.rows];
		while (m.str[++m.cols])
		{
			if ((m.rows == 0 || !cont->map[m.rows + 1] || \
			m.cols == 0 || m.str[m.cols \
			+ 1] == 0) && m.str[m.cols] == '0')
				ft_error("Error : invalid map");
			else if (m.str[m.cols] == '0' || m.str[m.cols] == 'N' \
			|| m.str[m.cols] == 'E' || m.str[m.cols] == 'W' \
			|| m.str[m.cols] == 'S')
			{
				if (m.str[m.cols + 1] == ' ' || m.str[m.cols - 1] == ' ')
					ft_error("Error : invalid map");
				if (cont->map[m.rows + 1][m.cols] == ' ' || cont->map[m.rows
					- 1][m.cols] == ' ')
					ft_error("Error : invalid map");
			}
		}
	}
}

t_parse	*parsing_main(int ac, char **av)
{
	char	**lines;
	t_parse	*content;

	ft_args(ac, av);
	lines = ft_read_file(av[1]);
	content = ft_get_all_content(lines);
	ft_get_map_index(content, lines);
	ft_copy_map(content, lines);
	ft_map_is_valid(content);
	ft_check_player_exists(content);
	ft_is_valid_map(content);
	free_byte(lines);
	return (content);
}
