/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f_and_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:40:09 by edraidry          #+#    #+#             */
/*   Updated: 2023/07/24 19:59:05 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


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


static char	**error(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++ ;
		if ((s[i] == c && s[i + 1] != c) && (s[i] == c && s[i + 1] != '\0'))
			count++ ;
		i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*calloc_words(const char *s1, int len)
{
	char	*copy;
	int		j;

	j = 0;
	copy = (char *) malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (j < len)
	{
		copy[j] = s1[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;
	int		j;
	int		i ;
	int		wl;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	spl = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!spl)
		return (NULL);
	while (i < count_words(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		wl = word_len(s + j, c);
		spl[i] = calloc_words(s + j, wl);
		if (!spl[i])
			return (error(spl));
		j += wl;
		i++;
	}
	spl[i] = 0;
	return (spl);
}


int check_dot(char *line)
{
    int i = 0;
    int count = 0;
    while(line[i])
    {
        if(line[i] == '.')
        {
            count++;
        }
        i++;
    }
    return count;
}


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void    check_f(char *line, t_content *content, int n)
{
    int k = 0;
    int i = 0;
    int j = 0;
    char **str;
    k = check_dot(line);
    if(k != 2)
        ft_error("found not corrcot dot '.'");
    str = ft_split(line,'.');
    while(str[i])
    {
		j = 0;
        while(str[i][j])
        {
            if(ft_isdigit(str[i][j]) == 0)
                ft_error("not number");
            j++;
        }
        i++;
    }
    i = 0;
    j = 0;
    while(str[i])
    {
        if(ft_atoi(str[i]) <0 || ft_atoi(str[i]) > 255)
            ft_error("argmet must be between 0 and  255");
        i++;
    }
	if(n == 5)
		content->ff = create_trgb(0, ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
	if(n == 6)
		content->cc = create_trgb(0, ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
}
