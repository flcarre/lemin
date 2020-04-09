/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:52:42 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:27:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lst_del_one(t_list *curr, void *value, unsigned long size)
{
	t_list	*tmp;

	tmp = NULL;
	if (curr == NULL)
		return (NULL);
	if (value == NULL && curr->content == NULL && curr->content_size == 0
			&& size == 0)
	{
		tmp = curr->next;
		free(curr);
		return (tmp);
	}
	if (curr->content_size == size &&
			(ft_strncmp(curr->content, value, ft_strlen(value)) == 0) &&
			(ft_strlen(curr->content) == ft_strlen(value)))
	{
		tmp = curr->next;
		free(curr->content);
		free(curr);
		return (tmp);
	}
	curr->next = ft_lst_del_one(curr->next, value, size);
	return (curr);
}
