/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:34:23 by ratin             #+#    #+#             */
/*   Updated: 2018/11/27 20:48:49 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			count_tetri(char **tab)
{
	int		i;
	int		tetri;

	i = 0;
	tetri = 0;
	while (tab[i] != NULL)
	{
		if ((strcmp(tab[i], "")) == 0)
			tetri++;
		i++;
	}
	tetri++;
	return (tetri);
}

t_tetri		*fill_tetrimino(char **tab)
{
	int		i;
	int		tetri_folower;
	int		tetri_height;
	t_tetri	*pieces;

	tetri_folower = 0;
	if ((pieces = (t_tetri *)malloc(sizeof(t_tetri)
	* count_tetri(tab) + 1)) == NULL)
		return (0);
	i = -1;
	while (tab[++i] != NULL)
	{
		if ((pieces[tetri_folower].tetrimino =
		(char **)malloc(sizeof(char *) * 5)) == NULL)
			return (0);
		tetri_height = -1;
		while (++tetri_height < 4)
		{
			pieces[tetri_folower].tetrimino[tetri_height] = ft_strdup(tab[i]);
			i++;
		}
		pieces[tetri_folower].tetrimino[tetri_height] = 0;
		tetri_folower++;
	}
	return (pieces);
}

int			give_max_min(char **tetrimino, int compute)
{
	int		i;
	int		y;
	int		max;
	int		min;

	i = 0;
	max = 0;
	min = 5;
	while (tetrimino[i] != NULL)
	{
		y = 4;
		while (y >= 0)
		{
			if (tetrimino[i][y] == '#' && y < min)
				min = y;
			if (tetrimino[i][y] == '#' && y > max)
				max = y;
			y--;
		}
		i++;
	}
	return (compute == 0 ? max : min);
}

void		get_height(t_tetri *tetri_tab)
{
	int		i;
	int		tetri_index;
	int		max;
	int		min;

	i = 0;
	max = 0;
	min = 5;
	tetri_tab[i].width = 0;
	while (tetri_tab[i].tetrimino != NULL)
	{
		tetri_tab[i].height = 0;
		tetri_index = 0;
		while (tetri_tab[i].tetrimino[tetri_index] != NULL)
		{
			if (ft_strchr(tetri_tab[i].tetrimino[tetri_index], '#') != NULL)
				tetri_tab[i].height++;
			tetri_index++;
		}
		max = give_max_min(tetri_tab[i].tetrimino, 0);
		min = give_max_min(tetri_tab[i].tetrimino, 1);
		tetri_tab[i].width = max - min + 1;
		i++;
	}
}

t_tetri		*make_struct(char **str)
{
	t_tetri	*pieces_tab;
	int		nbr_tetri;

	pieces_tab = fill_tetrimino(str);
	nbr_tetri = count_tetri(str);
	pieces_tab[4].tetrimino = 0;
	get_height(pieces_tab);
	return (pieces_tab);
}
