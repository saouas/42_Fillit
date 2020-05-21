/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:31:03 by saouas            #+#    #+#             */
/*   Updated: 2018/11/28 15:57:59 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**make_board(void)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((board = (char **)malloc(sizeof(char *) * 27)) == NULL)
		return (NULL);
	while (i < 26)
	{
		if ((board[i] = (char *)malloc(sizeof(char ) * 27)) == NULL)
			return (NULL);
		ft_memset(board[i], '0', 26);
		board[i][27] = '\0';
		i++;
	}
	board[i] = 0;
	return (board);
}

void	place_map(int size, char **board)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (board[i][j] == '0')
				board[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

char	**compute_map(char **map, int size)
{
	if (map == NULL)
	{
		if ((map = make_board()) == NULL)
			return (0);
	}
	place_map(size, map);
	return (map);
}