/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:44:58 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:13:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	tmp;

	if (nb < 0)
	{
		tmp = (unsigned int)-nb;
		ft_putchar_fd('-', fd);
	}
	else
	{
		tmp = (unsigned int)nb;
	}
	if (tmp >= 10)
	{
		ft_putnbr_fd((int)(tmp / 10), fd);
	}
	ft_putchar_fd(tmp % 10 + '0', fd);
}
