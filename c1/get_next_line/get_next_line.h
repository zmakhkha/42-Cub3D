/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:50:24 by edraidry          #+#    #+#             */
/*   Updated: 2023/07/24 16:24:53 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# define BUFFER_SIZE 10

char	*get_next_line(int fd);
int		ft_strchr(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
#endif
