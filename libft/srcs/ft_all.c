/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:29:34 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:13:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_all(void *ptr, int size, int step, int (f)(void*))
{
	int	i;

	if (size == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!f(ptr + step * i))
			return (0);
		i++;
	}
	return (1);
}
