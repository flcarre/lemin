/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:44:22 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:08:29 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_glstdelone(t_glist **alst, void (*del)(void *, unsigned long))
{
	t_glist	*next;

	if (del != NULL)
		del((*alst)->gen.content, (*alst)->content_size);
	next = (*alst)->next;
	free(*alst);
	*alst = next;
}
