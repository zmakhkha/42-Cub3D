/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:35:01 by edraidry          #+#    #+#             */
/*   Updated: 2022/10/27 11:27:57 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*chr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) >= ft_strlen(s))
	{
		chr = (char *) malloc(sizeof (char) * (ft_strlen(s) - start + 1));
	}
	else
		chr = (char *) malloc(sizeof (char) * (len + 1));
	if (!chr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		chr[i] = s[start + i];
		i++;
	}
	chr[i] = '\0';
	return (chr);
}
