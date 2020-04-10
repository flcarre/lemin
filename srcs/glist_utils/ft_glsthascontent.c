/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glsthascontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:49:05 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:09:25 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	ft_glsthascontent(t_glist *lst, void *content)
{
	t_glist	*curr;

	curr = lst;
	while (curr != NULL)
	{
		if (curr->gen.content == content)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}
