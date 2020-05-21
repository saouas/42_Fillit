/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:29:22 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:17:12 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	int		size_src;
	int		i;

	i = 0;
	size_src = ft_strlen(src);
	while (i <= size_src)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
