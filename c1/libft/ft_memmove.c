/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:12:11 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/27 21:36:28 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (s == d)
		return (dest);
	if (s < d)
	{
		s = s + n - 1;
		d = d + n -1 ;
		while (n--)
			*d-- = *s--;
	}
	else
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
