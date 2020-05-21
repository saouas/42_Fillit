/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:45:10 by saouas            #+#    #+#             */
/*   Updated: 2018/11/27 16:59:47 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		**check_column(char **tetrimino)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetrimino[i] != 0)
	{
		while (tetrimino[i][j])
		{
			if (tetrimino[i][j] == '#')
				return (i);
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}

char	**place_tetri(char **map, char **tetrimino)
{
	int i;
	int j;
	int x;
	int y;

	x = 0;
	y = 0;
	i = check_column(tetrimino);
	j = 0;
	while (tetrimino[i] != 0)
	{
		while (tetrimino[i][j])
		{
			if (tetrimino[i][j] == '#')
			{
				if (map[x][y] == '.')
					map[x + i][y + j] = tetriminos[i][j];
			}
			else if (y < 4)
			{
				y++;
				place_tetri(map, tetrimino);
			}
			else if (y == 4)
			{
				x = x + 1;
				place_tetri(map, tetrimino);
			}
			else
				continue;
			j++;
		}
		j = 0;
		i++;
	}
}

