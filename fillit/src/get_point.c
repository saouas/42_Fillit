/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:03:51 by saouas            #+#    #+#             */
/*   Updated: 2018/11/28 21:04:11 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		**malloctab(void)
{
	int i;
	int	**new_tab;

	i = 0;
	if (!(new_tab = (int **)malloc(sizeof(int*) * 4)))
		return (NULL);
	while (i < 4)
	{
		if (!(new_tab[i] = (int *)malloc(sizeof(int) * 2)))
			return (NULL);
		i++;
	}
	return (new_tab);
}

void	fuckingnorm(char **tetrimino, int **list_points, int *t2, int *t)
{
	while (tetrimino[t2[0]][t2[1]])
	{
		if (tetrimino[t2[0]][t2[1]] == '#' && t[2] == 0)
		{
			t[0] = t2[0];
			t[1] = t2[1];
			list_points[t[2]][t[3]] = 0;
			t[3] = t[3] + 1;
			list_points[t[2]][t[3]] = 0;
			t[2] = t[2] + 1;
			t2[1] = t2[1] + 1;
		}
		if (tetrimino[t2[0]][t2[1]] == '#' && t[2] < 4)
		{
			t[3] = 0;
			list_points[t[2]][t[3]] = t2[0] - t[0];
			t[3] = t[3] + 1;
			list_points[t[2]][t[3]] = t2[1] - t[1];
			t[2] = t[2] + 1;
		}
		t2[1] = t2[1] + 1;
	}
}

int		**get_points2(char **tetrimino, int *t2, int *t)
{
	int		**list_points;
	int		x;
	int		y;

	list_points = malloctab();
	x = 0;
	y = 0;
	while (tetrimino[t2[0]] != 0)
	{
		fuckingnorm(tetrimino, list_points, t2, t);
		t2[0] = t2[0] + 1;
		t2[1] = 0;
	}
	return (list_points);
}

/*
** Replace value of i , j ,i1 , j1 , x , y by this one because of norm
**
** t[0] = 0;   i1
**	t[1] = 0;  j1
**	t[2] = 0;  x
**	t[3]  = 0; y
**	t2[0] = 0; i
**	t2[1] = 0; j
*/

int		**get_points(char **tetrimino)
{
	int		t2[2];
	int		t[4];

	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = 0;
	t2[0] = 0;
	t2[1] = 0;
	return (get_points2(tetrimino, t2, t));
}
