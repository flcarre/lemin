/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:53:12 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:11:56 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlist **alst, t_dlist *_new)
{
	_new->next = *alst;
	_new->prev = NULL;
	if (*alst != NULL)
		(*alst)->prev = _new;
	*alst = _new;
}
