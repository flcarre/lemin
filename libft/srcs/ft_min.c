/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:30:33 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:13:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_min(int *ptr, int size)
{
	int	i;
	int	min;

	if (size == 0)
		return (0);
	min = ptr[0];
	i = 1;
	while (i < size)
	{
		if (ptr[i] < min)
			min = ptr[i];
		i++;
	}
	return (min);
}
