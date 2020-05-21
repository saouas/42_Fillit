/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:21:40 by ratin             #+#    #+#             */
/*   Updated: 2018/11/26 18:34:57 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../includes/fillit.h"

static int	open_file(char *str)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr_fd("error\n", 2);
		exit(1);
	}
	return (fd);
}

char		**read_file(char *str)
{
	static char	*input_file[130];
	int			i;
	int			fd;

	i = 0;
	fd = open_file(str);
	while ((get_next_line(fd, &input_file[i])))
		i++;
	input_file[i] = 0;
	if (close(fd) < 0)
	{
		ft_putstr_fd("error\n", 2);
		exit(1);
	}
	return (input_file);
}
