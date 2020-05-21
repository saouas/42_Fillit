/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:21:26 by saouas            #+#    #+#             */
/*   Updated: 2018/11/25 23:54:17 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		check_hashtag(char *str)
{
	unsigned int	j;
	unsigned int	i;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			j++;
		i++;
	}
	if (j != 4)
	{
		return (0);
	}
	return (1);
}

int		check_norme_tetri(char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		if (!(str[i] == '.' || str[i] == '#'))
			return (0);
		if (str[i] == '.')
			j++;
		if (i % 16 == 0)
		{
			if ((str[i] == '\n') && (j == 12))
				j = 0;
			else
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int		check_tetri(char *str, unsigned int *i, unsigned int *k)
{
	if (check_hashtag(str) == 0 || check_norme_tetri(str) == 0)
		return (0);
	while (*k < 16)
	{
		if (str[*k] == '#')
		{
			if (*i == 0)
				return (str[*k + 1] == '#' || str[*k - 4] == '#'
						|| str[*k + 4] == '#' ? 1 : 0);
			else
				return (str[*k - 1] == '#' || str[*k + 1] == '#'
						|| str[*k - 4] == '#' || str[*k + 4] == '#' ? 1 : 0);
		}
		*i = *i + 1;
		if ((*k % 4) == 0 || (*k % 8) == 0 || (*k % 12) == 0 || (*k % 16) == 0)
			*i = 0;
		*k = *k + 1;
	}
	return (1);
}

int		check_input(char *str)
{
	unsigned int	i;
	char			*tmp;
	unsigned int	k;
	unsigned int	j;

	k = 0;
	j = 0;
	i = 0;
	tmp = ft_strnew(16);
	if ((ft_strlen(str) > ((26 * 17) - 1)))
	{
		return (0);
	}
	while (str[i])
	{
		tmp = ft_strndup(str + i, 16);
		if (check_tetri(tmp, &k, &j) == 0)
		{
			return (0);
		}
		else
			i = i + 17;
	}
	return (1);
}
