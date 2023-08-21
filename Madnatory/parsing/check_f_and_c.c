/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f_and_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:40:09 by edraidry          #+#    #+#             */
/*   Updated: 2023/08/19 09:14:53 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	check_dot(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	check_f_(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
				ft_error("Error : not number");
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) < 0 || ft_atoi(str[i]) > 255)
			ft_error("Error : argmet must be between 0 and  255");
		i++;
	}
}

void	check_f(char *line, t_parse *content, int n)
{
	int		k;
	int		i;
	int		j;
	char	**str;

	k = 0;
	i = 0;
	j = 0;
	k = check_dot(line);
	if (k != 2)
		ft_error("found not corrcot dot ','");
	str = ft_split(line, ',');
	free(line);
	if (!str[0] || !str[1] || !str[2])
		ft_error("Error : invalid color !!");
	check_f_(str);
	if (n == 5)
		content->ff = create_trgb(0, ft_atoi(str[0]), ft_atoi(str[1]), \
			ft_atoi(str[2]));
	if (n == 6)
		content->cc = create_trgb(0, ft_atoi(str[0]), ft_atoi(str[1]), \
			ft_atoi(str[2]));
	free_byte(str);
}
