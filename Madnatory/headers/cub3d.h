/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:57:43 by edraidry          #+#    #+#             */
/*   Updated: 2023/08/13 19:13:52 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_parse
{
	char	*no;
	char	*ea;
	char	*so;
	char	*we;
	int		ff;
	int		cc;
	int		start;
	char	**map;
}			t_parse;
void		check_f(char *line, t_parse *content, int n);

//  int		ft_strncmp(char *s1, char *s2, int n);
void		ft_error(char *msg);
void		ft_args(int ac, char **av);
char		**ft_realloc(char **old, char *new);
char		**ft_read_file(char *file);
t_parse		*ft_get_all_content(char **lines);
t_parse		*parsing_main(int ac, char **av);
char		**free_byte(char **a);

char		*ft_strdup(const char *src);
#endif