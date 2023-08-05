/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:32:41 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/05 08:54:10 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Madnatory/headers/header.h"


void	ft_exit(char *str, int status)
{
	write(1, str, ft_strlen(str));
	exit(status);
}
