/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:06:55 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/31 17:30:16 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdarg.h>

int		ft_error(unsigned int func, ...)
{
	va_list		vars;

	if (func == 1)
	{
		va_start(vars, func);
		ft_del_path((t_path **)va_arg(vars, t_path **), \
		(unsigned int)va_arg(vars, unsigned int));
		va_end(vars);
	}
	ft_putendl("ERROR");
	return (1);
}
