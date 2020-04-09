/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:30:23 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:27:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, unsigned long len)
{
	unsigned long	big_len;
	unsigned long	little_len;
	unsigned long	i;

	big_len = ft_strlen((char*)big);
	little_len = ft_strlen((char*)little);
	if (little_len == 0)
	{
		return ((char*)big);
	}
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		if (!ft_strncmp((char*)big + i, (char*)little, little_len))
		{
			return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
