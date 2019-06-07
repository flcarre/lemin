/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidcmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:05:50 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/07 21:08:11 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rank		ft_isvalidcmd(char *line)
{
	if (!ft_strcmp("##start", line))
		return (START);
	if (!ft_strcmp("##end", line))
		return (END);
	return (NOTHING);
}
