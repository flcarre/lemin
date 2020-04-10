/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:55:39 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:09:25 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_glist		*ft_glstcpy(t_glist *src)
{
	t_glist	*res;
	t_glist	*curr;
	t_glist	*new;

	res = NULL;
	curr = src;
	while (curr != NULL)
	{
		new = ft_glstnew(curr->gen.content, curr->content_size);
		ft_glstadd(&res, new);
		curr = curr->next;
	}
	return (res);
}
