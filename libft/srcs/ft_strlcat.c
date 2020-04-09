/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 20:37:52 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:27:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long		ft_strlcat(char *dest, char const *src, unsigned int size)
{
	unsigned long	dest_len;
	unsigned long	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size + src_len <= dest_len + src_len)
	{
		return (ft_strlen(src) + size);
	}
	ft_strncat(dest, src, size - dest_len - 1);
	return (dest_len + src_len);
}
