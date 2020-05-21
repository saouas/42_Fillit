/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uper_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:18:09 by ratin             #+#    #+#             */
/*   Updated: 2018/11/27 23:40:47 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

/*
** take a tetriminos in paramater
** give the coordone of the top left bloc
*/

int		*get_uper_left(char **tetrimino)
{
	static int	j_i_tab[2];

	j_i_tab[0] = 0;
	j_i_tab[1] = 0;
	while (tetrimino[j_i_tab[0]] != NULL)
	{
		while (tetrimino[j_i_tab[0]][j_i_tab[1]] != '\0')
		{
			if (tetrimino[j_i_tab[0]][j_i_tab[1]] == '#')
				return (j_i_tab);
			j_i_tab[1]++;
		}
		j_i_tab[1] = 0;
		j_i_tab[0]++;
	}
	return (0);
}

/*
** take the position of the first bloc of one tetriminos in parameter
** send an integer code with right down left up order
*/

int		r_d_l_u(char **str, int line, int column)
{
	if ((str[line][column + 1] != '\0') && (str[line][column + 1] == '#'))
		return (1);
	if ((str[line + 1] != 0) && (str[line + 1][column] == '#'))
		return (2);
	if ((column > 0) && (str[line][column - 1] == '#'))
		return (3);
	if ((line >= 1) && (str[line - 1][column] == '#'))
		return (0);
	return (0);
}

/*
** give the next bloc coordone with right down left up order
*/

int		*mover(t_tetri tetrimino, int j, int i)
{
	static int	new_cordo[2];

	new_cordo[0] = j;
	new_cordo[1] = i;
	if (r_d_l_u(tetrimino.tetrimino, j, i) == 1)
		new_cordo[1]++;
	if (r_d_l_u(tetrimino.tetrimino, j, i) == 2)
		new_cordo[0]++;
	if (r_d_l_u(tetrimino.tetrimino, j, i) == 3)
		new_cordo[1]--;
	if (r_d_l_u(tetrimino.tetrimino, j, i) == 4)
		new_cordo[0]--;
	if (r_d_l_u(tetrimino.tetrimino, j, i) == 0)
		return (0);
	return (new_cordo);
}
