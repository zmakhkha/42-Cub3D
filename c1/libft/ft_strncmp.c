/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:18:14 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/27 22:43:17 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*k;
	unsigned char	*j;
	size_t			i;

	k = (unsigned char *)s1;
	j = (unsigned char *)s2;
	i = 0;
	while ((k[i] != '\0' || j[i] != '\0') && i < n)
	{
		if (k[i] < j[i])
			return (-1);
		if (k[i] > j[i])
			return (1);
	i++;
	}
	return (0);
}
