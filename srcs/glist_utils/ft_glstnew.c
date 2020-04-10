/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:25:08 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:08:29 by flcarre          ###   ########.fr       */
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
