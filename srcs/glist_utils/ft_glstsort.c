/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:21:05 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:09:25 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		swap(t_glist *a, t_glist *b)
{
	void			*content;
	unsigned long	content_size;

	content = a->gen.content;
	content_size = a->content_size;
	a->gen.content = b->gen.content;
	a->content_size = b->content_size;
	b->gen.content = content;
	b->content_size = content_size;
}

static t_bool	pass(t_glist *list, int (*cmp)(void*, void*))
{
	t_bool	res;
	t_glist	*curr;

	res = TRUE;
	curr = list;
	while (curr != NULL && curr->next != NULL)
	{
		if (cmp(curr->gen.content, curr->next->gen.content))
		{
			res = FALSE;
			swap(curr, curr->next);
		}
		curr = curr->next;
	}
	return (res);
}

void			ft_glstsort(t_glist *list, int (*cmp)(void*, void*))
{
	t_glist	*curr;

	curr = list;
	while (curr != NULL)
	{
		if (pass(curr, cmp))
			return ;
		curr = curr->next;
	}
}
