/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:25:35 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:06:40 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, unsigned long size)
{
	char			*newptr;
	unsigned long	ptrsize;
	void			*ret;

	if (ptr == 0)
		return (ft_memalloc(size));
	ptrsize = sizeof(ptr);
	if (size <= ptrsize)
		return (ptr);
	if ((newptr = (char*)ft_memalloc(ptrsize
					* (ft_strlen((char*)ptr) + size))) == NULL)
		return (NULL);
	if ((ret = ft_memcpy(newptr, ptr, ft_strlen((char*)ptr))) == NULL)
		return (ptr);
	free(ptr);
	return (newptr);
}
