/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:27:18 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 13:46:29 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf_types.h"

# define FLAG_PREPOUND 1
# define FLAG_ZERO 2
# define FLAG_PLUS 4
# define FLAG_MINUS 8
# define FLAG_SPACE 16
# define FLAG_HASPRECISION 32

# define MAP_SIZE 256

int			print_argument(int fd, t_formatinfo *formatinfo, va_list ap);
void		print_number_generic(t_formatinfo *info, \
			va_list ap, char *base, t_output *output);

void		out_putchar(t_output *output, char c);
void		out_putchar_len(t_output *output, char *ptr, unsigned long size);
void		out_init(t_output *output);
void		print_padding(t_formatinfo *formatinfo, int len, t_output *output);
void		ft_putnbr_base(t_u64 nbr, char *base, t_output *output);
int			ft_putnstr(char *str, int max);
void		out_fill(t_output *output, int count, char c);
void		print_prepound_notnull(t_formatinfo *info, char *str, \
			va_list ap, t_output *out);
int			value_is_zero(t_formatinfo *info, va_list ap);

int			parse_flags(t_formatinfo *info, \
			const char *format, int *pos);
int			parse_width(t_formatinfo *info, \
			const char *format, int *pos);
int			parse_precision(t_formatinfo *info, \
			const char *format, int *pos);
int			parse_length(t_formatinfo *info, \
			const char *format, int *pos);
int			parse_specifier(t_formatinfo *info, \
			const char *format, int *pos);
int			parse_number(const char *format, int *pos, int *num);

t_64		read_argument_signed(t_formatinfo *info, va_list ap);
t_u64		read_argument_unsigned(t_formatinfo *info, va_list ap);

void		print_int(t_formatinfo *info, va_list ap, t_output *output);
void		print_uint(t_formatinfo *info, va_list ap, t_output *output);
void		print_octal(t_formatinfo *info, va_list ap, t_output *output);
void		print_hex(t_formatinfo *info, va_list ap, t_output *output);
void		print_hexup(t_formatinfo *info, va_list ap, t_output *output);
void		print_float(t_formatinfo *info, va_list ap, t_output *output);
void		print_str(t_formatinfo *info, va_list ap, t_output *output);
void		print_char(t_formatinfo *info, va_list ap, t_output *output);
void		print_percent(t_formatinfo *info, va_list ap, t_output *output);
void		print_ptr(t_formatinfo *info, va_list ap, t_output *output);

#endif
