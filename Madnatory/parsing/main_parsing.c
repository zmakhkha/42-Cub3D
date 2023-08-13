/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:57:25 by edraidry          #+#    #+#             */
/*   Updated: 2023/08/13 20:10:17 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/header.h"

void	ft_get_map_index(t_parse	*content, char **lines)
{
	int	start;

	start = content->start;
	while (lines[start] && lines[start][0] == '\0')
		++start;
	content->start = start;
}


int	ft_max_line(t_parse	*content, char **lines)
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

void	*ft_memset(void *str, int ch, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) str)[i] = (unsigned char)ch;
		i++;
	}
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);

	
}


// void	ft_copy_map(t_parse	*content, char **lines)
// {
// 	int	start;
// 	int	max;
// 	char	*str;

// 	max = ft_max_line(content, lines);
// 	start = content->start;
// 	while (lines[start])
// 	{
// 		if (lines[start][0] == '\0')
// 			ft_error("empty line found in the map");
// 		str = malloc(max + 1);
// 		if (!str)
// 			ft_error("malloc fail");
// 		ft_memset(str, ' ', max);
// 		str[max] = '\0';
// 		ft_memcpy(str, lines[start], ft_strlen(lines[start]));
// 		content->map = ft_realloc(content->map, str);
// 		++start;
// 	}
// }

void	ft_copy_map(t_parse	*content, char **lines)
{
	int	start;
	int	max;
	char	*str;
	//int i = 0;
	char **tmp;

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
		// free(str);
		free(content->map);
		content->map = tmp;
		++start;
	}
	
}
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
			if (str[o] != '0' && str[o] != '1' && str[o] != ' '
				&& str[o] != 'N' && str[o] != 'E' && str[o] != 'S' && str[o] != 'W')
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
			if (str[o] == 'N' || str[o] == 'E' || str[o] == 'S' || str[o] == 'W')
				++count;
			++o;
		}
		++i;
	}
	if(count != 1)
		ft_error("should have only one player in  the map");
}

void	ft_is_valid_map(t_parse *cont)
{
	int		cols;
	int		rows;
	char	*str;

	rows = 0;
	while (cont->map[rows])
	{
		cols = 0;
		str = cont->map[rows];
		while (str[cols])
		{
			if (rows == 0 || !cont->map[rows + 1] || cols == 0 || str[cols + 1] == 0)
			{
				if (str[cols] == '0')
					ft_error("invalid map");
			}
			else if (str[cols] == '0' || str[cols] == 'N' || str[cols] == 'E' || str[cols] == 'W' || str[cols] == 'S')
			{
				if (str[cols + 1] == ' ' || str[cols - 1] == ' ')
					ft_error("invalid map");
				if (cont->map[rows + 1][cols] == ' ' || cont->map[rows - 1][cols] == ' ')
					ft_error("invalid map");
			}
			++cols;
		}
		++rows;
	}
}

t_parse *parsing_main(int ac, char **av)
{
	char **lines;
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
	// exit(1);
	return (content);
}