/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:31:03 by saouas            #+#    #+#             */
/*   Updated: 2018/11/27 18:05:04 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**realloc_map(int i, char **old_map)
{
	char 	**map;
	int 	k;

	k = 0;
	if (old_map != NULL)
	{
		while (k < i + 1)
		{
			free(old_map[k]);
			k++;
		}
		free(old_map);
	}
	k = 0;
	if(!(map = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	map[i] = 0;
	while (k < i)
	{
		if(!(map[k] = (char *)malloc(sizeof(char) * i + 1)))
			return (NULL);
		k++;
	}
	return (map);
}
char	**init_map(int i, char **map)
{
	int ii;
	int jj;

	ii = 0;
	jj = 0;
	while (map[jj] != 0)
	{
		while (ii < i)
		{
			map[jj][ii] = '.';
			ii++;
		}
		ii = 0;
		jj++;
	}
	return (map);
}

char	**create_map(t_tetri *tetriminos)
{
	char	**map;
	int 	i;
	int		j;
	int 	k;
	int		x;

	x = 0;
	k = 0;
	i = 0;
	j = 0;
	while (tetriminos[k].tetrimino[x] != 0)
	{
		x = 0;
		if (tetriminos[k].height > i)
			i = tetriminos[k].height;
		if (tetriminos[k].width > j)
			j = tetriminos[k].width;
		while (tetriminos[k].tetrimino[x] != 0 && x < 4)
			x++;
		k++;
	}

	if (i > j)
		j = i;
	else
		i = j;
	map = realloc_map(i, NULL);
	map = init_map(i, map);
	return (map);
}

int		size_map(char **map)
{
	int i;

	i = 0;
	while(map[i] != 0)
		i++;
	return (i);
}

int		width_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i][j])
		j++;
	return (j);
}
