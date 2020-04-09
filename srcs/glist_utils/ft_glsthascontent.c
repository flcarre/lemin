/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glsthascontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:49:05 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 18:15:00 by lutsiara         ###   ########.fr       */
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
