/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:32:33 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:27:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	unsigned long	i;

	i = 0;
	while (1)
	{
		if (((unsigned char*)str)[i] == (unsigned char)character)
			return ((char*)(str + i));
		if (((unsigned char*)str)[i] == '\0')
			return (NULL);
		i++;
	}
}
