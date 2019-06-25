/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:21:09 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/25 17:49:51 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_setzero(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			*str = '\0';
		str++;
	}
}

static char		*ft_read(unsigned long *len)
{
	char					buff[8192];
	char					*buffer;
	char					*tmp;
	long					ret;

	buffer = (void *)0;
	while ((ret = read(STDIN_FILENO, buff, 8191)) > 0)
	{
		buff[ret] = '\0';
		*len += ret;
		tmp = buffer;
		buffer = ft_strjoin(buffer, buff);
		ft_memdel((void **)&tmp);
		if (!buffer && !(*len = 0))
			return ((void *)0);
	}
	if (ret < 0)
	{
		ft_memdel((void **)&buffer);
		*len = 0;
		return ((void *)0);
	}
	return (buffer);
}

char			*ft_gnl(unsigned char mode)
{
	static char				*buffer = (void *)0;
	static char				*line = (void *)0;
	static unsigned long	len = 0;

	if (mode == 4 && (line = buffer))
		return (line);
	if (mode == 2 && !line && (line = buffer))
		return (line);
	if (!mode)
	{
		ft_memdel((void **)&buffer);
		return ((void *)0);
	}
	if (mode == 3)
	{
		if (!(buffer = ft_read(&len)))
			return ((void *)0);
		ft_setzero(buffer);
		return (buffer);
	}
	line = ft_strrchr(line, (int)'\0');
	if ((unsigned long)line - (unsigned long)buffer < len)
		line++;
	return (line);
}
