/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:06:55 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/29 15:52:13 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdarg.h>

int		ft_error(unsigned int func, ...)
{
	va_list		vars;

	va_start(vars, func);
	if (func == 1)
		ft_del_path((t_path **)va_arg(vars, t_path **), \
		(unsigned int)va_arg(vars, unsigned int));
	ft_putendl("ERROR");
	va_end(vars);
	return (1);
}
