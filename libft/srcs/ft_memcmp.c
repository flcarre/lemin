/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:08:08 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:00:46 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, unsigned long num)
{
	unsigned long	i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < num)
	{
		c1 = ((unsigned char*)ptr1)[i];
		c2 = ((unsigned char*)ptr2)[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
