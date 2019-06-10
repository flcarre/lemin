/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_djb2a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:54:18 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/10 18:57:18 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_djb2a(char *str)
{
	unsigned long	hash;

	hash = 5381;
	while (str && *str)
	{
		hash = (hash * 33) ^ *str;
		str++;
	}
	return (hash);
}
