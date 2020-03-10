/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:03 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:13:17 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *ptr, int size)
{
	int	i;
	int	max;

	if (size == 0)
		return (0);
	max = ptr[0];
	i = 1;
	while (i < size)
	{
		if (ptr[i] > max)
			max = ptr[i];
		i++;
	}
	return (max);
}
