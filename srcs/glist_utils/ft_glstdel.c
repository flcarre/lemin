/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:47:48 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 21:08:29 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_glstdel(t_glist **alst, void (*del)(void *, unsigned long))
{
	t_glist	*curr;
	t_glist	*next;

	curr = *alst;
	while ((curr) != NULL)
	{
		next = (curr)->next;
		ft_glstdelone(&curr, del);
	}
	*alst = NULL;
}
