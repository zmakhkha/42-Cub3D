/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:53:00 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/27 21:22:55 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
