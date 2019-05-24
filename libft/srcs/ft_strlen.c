/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:33:53 by lutsiara          #+#    #+#             */
/*   Updated: 2019/03/13 16:23:27 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen(const char *s)
{
	unsigned long	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}