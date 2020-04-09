/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:08:20 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 19:42:54 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	unsigned long	i;
	char			*found;

	found = NULL;
	i = 0;
	while (1)
	{
		if (((unsigned char*)str)[i] == (unsigned char)character)
			found = (char*)(str + i);
		if (((char*)str)[i] == '\0')
			return (found);
		i++;
	}
}
