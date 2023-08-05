/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:05:40 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/27 21:53:59 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1, *p2 = s2;

	while (n--)
		if (*p1 != *p2)
			return (*p1 - *p2);
	else
	{
		p1++;
		p2++;
	}
	return (0);
}
