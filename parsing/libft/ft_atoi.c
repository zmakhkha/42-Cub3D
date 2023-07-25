/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:15:24 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/23 16:20:22 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	long	sing;
	long	i;

	res = 0;
	sing = 1;
	i = 0;
	if (*str == '\0')
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sing = -1;
	if (str[i] == '+' || str[i] == '-')
			i++;
	while (str[i] != '\0' )
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (sing * res);
}
