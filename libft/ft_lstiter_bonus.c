/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:23:53 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/08/12 16:26:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*pos;

	if (lst && f)
	{
		pos = lst;
		while (pos)
		{
			(*f)(pos->content);
			pos = pos->next;
		}
	}
}
