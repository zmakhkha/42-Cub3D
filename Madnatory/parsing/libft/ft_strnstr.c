/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:14:26 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/27 22:36:04 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr( const char *s1, const char *chr, size_t k)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !k)
		return (NULL);
	if (*chr == '\0')
		return ((char *)(s1));
	while ((s1[i] != '\0') && i < k)
	{
		j = 0;
		while (s1[i + j] == chr[j] && (i + j) < k)
		{
			j++;
			if (j == ft_strlen(chr))
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
