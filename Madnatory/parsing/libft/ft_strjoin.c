/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:45:55 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/26 15:59:09 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	chr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!chr)
		return (NULL);
	while (s1[i])
	{
		chr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		chr[i++] = s2[j++];
	chr[i] = '\0';
	return (chr);
}
