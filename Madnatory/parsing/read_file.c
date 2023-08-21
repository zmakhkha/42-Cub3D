/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:05:06 by edraidry          #+#    #+#             */
/*   Updated: 2023/08/19 08:08:26 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int				i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (t1[i] && t2[i] && i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	if (i < n)
		return (t1[i] - t2[i]);
	return (0);
}

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

void	ft_args(int ac, char **av)
{
	int	i;

	if (ac != 2)
		ft_error("Error : Use ./cub3D <file.cub>");
	if (ft_strlen(av[1]) < 4)
		ft_error("Error : Use ./cub3D <file.cub>");
	i = 0;
	while (av[1][i])
		++i;
	i -= 4;
	if (ft_strncmp(&av[1][i], ".cub", 5) != 0)
		ft_error("Error : Usage: ./cub3D <file.cub>");
	i = open(av[1], O_RDONLY);
	if (i < 0)
		ft_error("Error : Can't read from file");
	close(i);
}

char	**ft_realloc(char **old, char *new)
{
	int		i;
	char	**arr;

	i = 0;
	while (old && old[i])
		++i;
	arr = malloc(sizeof(char *) * (i + 2));
	if (!arr)
		ft_error("Error : malloc fail");
	i = 0;
	while (old && old[i])
	{
		arr[i] = old[i];
		++i;
	}
	arr[i] = new;
	arr[i + 1] = NULL;
	return (arr);
}

char	**ft_read_file(char *file)
{
	int		fd;
	char	**arr;
	char	**tmp;
	char	*line;

	fd = open(file, O_RDONLY);
	arr = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		tmp = ft_realloc(arr, line);
		free(arr);
		arr = tmp;
	}
	if (!arr)
		ft_error("Error : empty file");
	return (arr);
}
