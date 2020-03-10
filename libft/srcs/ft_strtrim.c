/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 01:10:14 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:13:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isblank(int c)
{
	return (c == '\n' || c == ' ' || c == '\t');
}

static int	start_pos(char const *s)
{
	int		n;

	n = 0;
	while (isblank(s[n]))
		n++;
	return (n);
}

static int	end_pos(char const *s, int len)
{
	int		i;

	i = len - 1;
	while (i >= 0 && isblank(s[i]))
	{
		i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*result;

	if (s == NULL)
		return (NULL);
	start = start_pos(s);
	end = end_pos(s, ft_strlen((char*)s));
	len = end - start + 1;
	if (0 >= len)
		len = 0;
	result = ft_memalloc(len + 1);
	if (result == NULL)
		return (NULL);
	ft_strncpy(result, (char*)(s + start), len);
	result[len] = '\0';
	return (result);
}
