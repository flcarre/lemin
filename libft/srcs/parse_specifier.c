/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:53:22 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:14:34 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_specifier	get_specifier(char c)
{
	t_specifier	specifiers[256];

	ft_bzero(&specifiers, sizeof(specifiers));
	specifiers['i'] = SPEC_INT;
	specifiers['d'] = SPEC_INT;
	specifiers['u'] = SPEC_UINT;
	specifiers['x'] = SPEC_HEX;
	specifiers['X'] = SPEC_HEXUP;
	specifiers['o'] = SPEC_OCTAL;
	specifiers['f'] = SPEC_FLOAT;
	specifiers['F'] = SPEC_FLOAT;
	specifiers['s'] = SPEC_STR;
	specifiers['c'] = SPEC_CHAR;
	specifiers['p'] = SPEC_PTR;
	specifiers['%'] = SPEC_PERCENT;
	return (specifiers[(int)c]);
}

int					parse_specifier(t_formatinfo *info, \
					const char *format, int *pos)
{
	char		c;
	t_specifier	spec;

	c = format[*pos];
	spec = get_specifier(c);
	if (spec == SPEC_NONE)
		return (0);
	(*pos)++;
	info->specifier = spec;
	return (1);
}
