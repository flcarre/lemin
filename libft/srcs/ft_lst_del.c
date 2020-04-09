/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:24:15 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:15:39 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del(t_list **lst)
{
	if (*lst != NULL && (*lst)->content != NULL)
	{
		if ((*lst)->next != NULL && (*lst)->next->content != NULL)
			ft_lst_del(&((*lst)->next));
		ft_lst_del_one((*lst), (*lst)->content, (*lst)->content_size);
	}
}
