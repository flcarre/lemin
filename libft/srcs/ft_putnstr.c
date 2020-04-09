/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:49:00 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:50:03 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr(char *str, int max)
{
	int	i;

	i = 0;
	while (i < max && str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
