/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:57:30 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/27 11:33:07 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	return_len(long n1)
{
	int	len;

	len = 0;
	if (n1 < 0)
	{
	n1 = n1 *(-1);
	len = 1;
	}
	while (n1 > 0)
	{
	n1 = n1 / 10;
	len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	len;
	long	nbr;
	char	*res;

	nbr = n;
	len = return_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	len--;
	if (nbr < 0)
	{
		nbr = nbr *(-1);
		res[0] = '-';
	}
	while (nbr != 0)
	{
		res[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (res);
}
