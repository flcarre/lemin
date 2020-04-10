/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:47:28 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:08:29 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_glstrev(t_glist **list)
{
	t_glist	*curr;
	t_glist	*prev;
	t_glist	*next;

	curr = *list;
	prev = 0;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*list = prev;
}
