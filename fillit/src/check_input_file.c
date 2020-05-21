/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:20:23 by ratin             #+#    #+#             */
/*   Updated: 2018/11/26 20:08:28 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../includes/fillit.h"

int		contact(char **str, int line, int column)
{
	if ((str[line][column + 1] != '\0') && (str[line][column + 1] == '#'))
		return (1);
	if ((column > 0) && (str[line][column - 1] == '#'))
		return (1);
	if ((str[line + 1] != 0) && (str[line + 1][column] == '#'))
		return (1);
	if ((line >= 1) && (str[line - 1][column] == '#'))
		return (1);
	return (0);
}

int		check_tetriminos(char **str)
{
	int line;
	int column;
	int size;

	line = -1;
	column = -1;
	size = 0;
	while (++line < 4)
	{
		if ((ft_strlen(str[line])) != 4)
			return (0);
		while (str[line][++column])
		{
			if (str[line][column] != '.' && str[line][column] != '#')
				return (0);
			if (str[line][column] == '#')
				size++;
			if (str[line][column] == '#' && (contact(str, line, column)) == 0)
				return (0);
		}
		column = -1;
	}
	if (size > 4 || size < 4)
		return (0);
	return (1);
}

int		check_input(char **str)
{
	int		line;

	if (str == NULL)
		return (0);
	line = 0;
	while (str[line] != NULL)
	{
		if ((check_tetriminos(&str[line])) == 0)
			return (0);
		line = line + 4;
		if (str[line] == NULL)
			return (1);
		if (str[line] != 0 && (strcmp(str[line], "")) != 0)
			return (0);
		line++;
		if (str[line] == NULL)
			return (0);
	}
	return (1);
}
