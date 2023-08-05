/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:02:44 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/27 22:19:33 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	if (!size && !dest)
		return (ft_strlen(src));
	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (d_len >= size)
		return (s_len + size);
	while ((src[i] && (i + d_len < (size - 1))))
	{
		dest[i + d_len] = src[i];
		i++;
	}
	dest[i + d_len] = '\0';
	return (d_len + s_len);
}
