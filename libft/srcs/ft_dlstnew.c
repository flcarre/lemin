/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:25:08 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:27:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, unsigned long content_size)
{
	t_dlist	*result;

	result = ft_memalloc(sizeof(t_dlist));
	if (result == NULL)
		return (NULL);
	result->content = (void*)content;
	if (content == NULL)
	{
		result->content_size = 0;
		result->content = NULL;
	}
	else
	{
		result->content_size = content_size;
	}
	result->next = NULL;
	result->prev = NULL;
	return (result);
}
