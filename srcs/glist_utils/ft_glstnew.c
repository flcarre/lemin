/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:25:08 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:27:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_glist	*ft_glstnew(void const *content, unsigned long content_size)
{
	t_glist	*result;

	result = ft_memalloc(sizeof(t_glist));
	result->gen.content = (void*)content;
	if (content == NULL)
	{
		result->content_size = 0;
	}
	else
	{
		result->content_size = content_size;
	}
	result->next = NULL;
	return (result);
}
