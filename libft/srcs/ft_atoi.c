/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:20:31 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/10 00:29:48 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	r;
	long	n;

	r = 0;
	n = 1;
	while (ft_isspace((int)(*str)))
		str++;
	n = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit((int)(*str)))
	{
		r = r * 10 + *(str++) - '0';
		if (r > 2147483647)
		{
			if (n == 1)
				return (-1);
			return (0);
		}
	}
	return ((int)(r * n));
}
