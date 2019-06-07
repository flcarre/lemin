/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:59:29 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/08 00:48:42 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_get_ants(unsigned int *nb_ants)
{
	char		*line;
	t_rank		rank;

	line = (void *)0;
	if (!(line = ft_gnl(2)) || !(*line))
		return (1);
	if ((rank = ft_rank_line(line)) != NBANTS)
	{
		if (rank == COMMENT || (rank == COMMAND && !ft_isvalidcmd(line)))
			return (ft_get_ants(nb_ants));
		return (1);
	}
	*nb_ants = ft_atoui((const char *)line);
	return (0);
}
