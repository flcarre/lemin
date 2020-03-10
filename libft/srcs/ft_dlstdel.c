/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:47:48 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:02:54 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstdel(t_dlist **alst, void (*del)(void *, unsigned long))
{
	t_dlist	*curr;
	t_dlist	*next;

	curr = *alst;
	while ((curr) != NULL)
	{
		next = (curr)->next;
		ft_dlstdelone(&curr, del);
		curr = next;
	}
	*alst = NULL;
}
