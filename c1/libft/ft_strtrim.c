/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:59:01 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/28 19:28:20 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*trimed;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (ft_strchr(set, s1[len - 1]) != NULL && len)
		len--;
	if ((len - i) < 0 || ft_strlen(s1) == 0)
		return (ft_strdup(""));
	trimed = ft_substr(s1, i, (len - i));
	return (trimed);
}
