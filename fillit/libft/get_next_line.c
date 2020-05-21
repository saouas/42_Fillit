/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:53:56 by ratin             #+#    #+#             */
/*   Updated: 2018/11/26 11:55:17 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>
#include "includes/libft.h"
#include <fcntl.h>
#include <stdlib.h>

static char	*give_end(char *buff, int remove)
{
	int		i;
	char	*begin_string;

	i = 0;
	if (buff[i] == '\0')
		return (buff);
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			if ((begin_string = ft_strsub(buff, i,
			ft_strlen(buff) - i)) == NULL)
				return (0);
			if (remove == 1)
				free(buff);
			return (&begin_string[1]);
		}
		i++;
	}
	if (remove == 1)
		free(buff);
	return (buff);
}

static char	*give_start(char *buff)
{
	int		i;
	char	*begin_string;

	i = 0;
	if (buff[i] == '\0')
		return (buff);
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			if ((begin_string = ft_strsub(buff, 0, ft_strlen(buff) -
			(ft_strlen(buff) - i))) == NULL)
				return (0);
			return (begin_string);
		}
		i++;
	}
	return (buff);
}

int			fill_fd_tab(int fd, char ***line, char **fd_tab)
{
	char		*begin_string;
	int			ret;
	char		*buff;

	ret = 0;
	if ((buff = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) && ft_strstr(buff, "\n") == NULL)
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if ((**line = ft_strjoin_free(**line, buff, 1)) == NULL)
			return (-1);
	}
	buff[ret] = '\0';
	if ((**line = ft_strjoin_free(fd_tab[fd], **line, 2)) == NULL)
		return (-1);
	if ((begin_string = give_start(buff)) == NULL)
		return (-1);
	if ((**line = ft_strjoin_free(**line, begin_string, 3)) == NULL)
		return (-1);
	if ((fd_tab[fd] = give_end(buff, 1)) == NULL)
		return (-1);
	return (ret == 0 && ft_strcmp(**line, "") == 0 ? 0 : 1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*fd_tab[2147483647];
	char		*begin_string;

	if (fd < 0 || line == NULL)
		return (-1);
	if ((*line = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
		return (-1);
	fd_tab[fd] = (fd_tab[fd] == NULL) ? "" : fd_tab[fd];
	if (ft_strchr(fd_tab[fd], '\n') == NULL)
		return (fill_fd_tab(fd, &line, fd_tab));
	else if (ft_strchr(fd_tab[fd], '\n') != NULL)
	{
		if ((begin_string = give_start(fd_tab[fd])) == NULL)
			return (-1);
		if ((*line = ft_strjoin_free(*line, begin_string, 1)) == NULL)
			return (-1);
		if ((fd_tab[fd] = give_end(fd_tab[fd], 0)) == NULL)
			return (-1);
	}
	return (1);
}
