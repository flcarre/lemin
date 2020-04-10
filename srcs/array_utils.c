/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:03:03 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:09:25 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			*glist_to_array(t_glist *list)
{
	void			**res;
	unsigned long	pos;
	unsigned long	size;
	t_glist			*curr;

	size = ft_glstlen(list);
	res = ft_memalloc(((size) * sizeof(void*)));
	pos = 0;
	curr = list;
	while (curr != NULL)
	{
		res[pos] = curr->gen.content;
		pos++;
		curr = curr->next;
	}
	return (res);
}

static void		swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_bool	sort_pass(void **array, unsigned long size, \
				int (cmp)(void*, void*))
{
	t_bool			res;
	unsigned long	pos;

	res = TRUE;
	pos = 0;
	while (pos < size - 1)
	{
		if (cmp(array[pos], array[pos + 1]) > 0)
		{
			res = FALSE;
			swap(&array[pos], &array[pos + 1]);
		}
		pos++;
	}
	return (res);
}

void			array_sort(void **array, unsigned long size, \
				int (cmp)(void*, void*))
{
	unsigned long	pos;

	pos = 0;
	while (pos < size)
	{
		if (sort_pass(array, size - pos, cmp))
			return ;
		pos++;
	}
}
