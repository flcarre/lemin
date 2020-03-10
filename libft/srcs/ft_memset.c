/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:38:59 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:27:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, unsigned long num)
{
	unsigned long	i;

	i = 0;
	while (i < num)
	{
		((unsigned char*)ptr)[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
