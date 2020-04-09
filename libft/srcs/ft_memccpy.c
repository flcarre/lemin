/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:54:34 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:01:04 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, unsigned long n)
{
	unsigned long	i;
	unsigned char	curr;

	i = 0;
	while (i < n)
	{
		curr = ((unsigned char*)src)[i];
		((unsigned char*)dst)[i] = curr;
		if (curr == (unsigned char)c)
			return ((void*)dst + i + 1);
		i++;
	}
	return (NULL);
}
