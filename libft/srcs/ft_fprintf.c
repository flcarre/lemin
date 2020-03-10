/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:05:30 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:24:24 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse(const char *format, \
			int *pos, t_formatinfo *info)
{
	parse_flags(info, format, pos);
	parse_width(info, format, pos);
	parse_precision(info, format, pos);
	parse_length(info, format, pos);
	parse_specifier(info, format, pos);
	if (info->specifier != SPEC_INT)
	{
		info->flags &= 0xff ^ FLAG_PLUS;
		info->flags &= 0xff ^ FLAG_SPACE;
	}
	if (info->flags & FLAG_HASPRECISION || info->flags & FLAG_MINUS)
	{
		info->flags &= 0xff ^ FLAG_ZERO;
	}
}

static int	parse_and_print_argument(int fd, \
			const char *format, int *pos, va_list ap)
{
	t_formatinfo	formatinfo;

	ft_bzero(&formatinfo, sizeof(formatinfo));
	parse(format, pos, &formatinfo);
	if (formatinfo.specifier == SPEC_NONE)
		return (0);
	return (print_argument(fd, &formatinfo, ap));
}

static int	ft_fprintf_core(int fd, const char *format, va_list ap)
{
	int		output_size;
	int		pos;

	pos = 0;
	output_size = 0;
	while (format[pos] != '\0')
	{
		if (format[pos] == '%')
		{
			pos++;
			output_size += parse_and_print_argument(fd, format, &pos, ap);
		}
		else
		{
			ft_putchar_fd(format[pos], fd);
			pos++;
			output_size++;
		}
	}
	va_end(ap);
	return (output_size);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_fprintf_core(STDOUT_FILENO, format, ap));
}

int			ft_fprintf(int fd, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_fprintf_core(fd, format, ap));
}
