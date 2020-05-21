/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:58:49 by ratin             #+#    #+#             */
/*   Updated: 2018/11/28 20:47:41 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fillit.h"

void	print_struct_tab(t_tetri *tab)
{
	int i;

	i = 0;
	while (tab[i].tetrimino != NULL)
	{
		ft_print_words_tables(tab[i].tetrimino);
		printf("\n");
		i++;
	}
}

int		main(int ac, char **av)
{
	char	**tab;
	t_tetri	*pieces;
	char	**map;
	int 	i;
	int 	j;
	int		**points;
	map = NULL;
	i = 0;
	j = 0;
	if (ac != 2)
	{
		ft_putstr_fd("usage", 2);
		exit(1);
	}
	tab = read_file(av[1]);
	if (check_input(tab) == 0)
	{
		ft_putstr_fd("error", 2);
			exit(1);
	}
	pieces = make_struct(tab);
//	print_struct_tab(pieces);
	map = compute_map(map, 2);
	ft_print_words_tables(map);

	printf("Test get points:\n");
	points = get_points(pieces[0].tetrimino);

	while (i < 4)
	{
		while (j < 2)
		{
			printf("tab[%d][%d] = %d\n",i,j,points[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
