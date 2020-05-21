/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:41:34 by ratin             #+#    #+#             */
/*   Updated: 2018/11/28 15:36:48 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int		*give_first_empty_case(char **map)
{
	static int	cursor[2];

	cursor[0] = 0;
	cursor[1] = 0;
	while (map[cursor[0]] != NULL)
	{
		while (map[cursor[0]][cursor[1]] != '\0'
		&& map[cursor[0]][cursor[1]] == '#')
		{
			cursor[1]++;
		}
		if (cursor[1] > 3)
			cursor[1] = 0;
		else
			return (cursor);
		cursor[0]++;
	}
	return (cursor);
}

int		gfec_on_one_line(char **map, int j)
{
	int		i;

	i = 0;
	printf("on est  |%s\n", map[j]);
	while (map[j][i] != '\0' && map[j][i] == '#')
		i++;
	if (i > 3)
		return (0);
	return (i);
}

int		fill_tab(char **map, t_tetri tetrimino, int	j, int i)
{
	int	*cordo_tetri;
	int *new_cordo;
	int	k;

	k = 0;
	new_cordo = NULL;
	set_cordo_to_zero(new_cordo);
	cordo_tetri = get_uper_left(tetrimino.tetrimino);
	while (k < 4)
	{
		map[j + new_cordo[0]][i + new_cordo[1]] = tetrimino.tetrimino[cordo_tetri[0] + new_cordo[0]][cordo_tetri[1] + new_cordo[1]];
		new_cordo = mover(tetrimino, cordo_tetri[0] + new_cordo[0], cordo_tetri[1] + new_cordo[1]);
		if (map[j + new_cordo[0]][i + new_cordo[1]] == '#')
		{
			if ((i + new_cordo[1]) < 3)
				return (fill_tab(map, tetrimino, j, i + 1));
			else if ((j + new_cordo[0]) < 3)
				return (fill_tab(map, tetrimino, j + 1, i));
			else
				return (0);
		}
		k++;
	}
	return (0);
}

