/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:47:48 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/19 11:49:43 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strchrindex(const char *str, char c)
{
	unsigned long	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
