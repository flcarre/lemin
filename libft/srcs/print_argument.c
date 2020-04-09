/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:31:31 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 14:30:32 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	(*get_func(t_specifier spec))(t_formatinfo*, va_list, t_output*)
{
	void		(*func[SPEC_COUNT])(t_formatinfo*, va_list, t_output*);

	func[SPEC_INT] = print_int;
	func[SPEC_UINT] = print_uint;
	func[SPEC_OCTAL] = print_octal;
	func[SPEC_HEX] = print_hex;
	func[SPEC_HEXUP] = print_hexup;
	func[SPEC_FLOAT] = print_float;
	func[SPEC_STR] = print_str;
	func[SPEC_CHAR] = print_char;
	func[SPEC_PERCENT] = print_percent;
	func[SPEC_PTR] = print_ptr;
	return (func[spec]);
}

static void	print_space_padding(t_formatinfo *formatinfo,
								int len,
								t_output *out)
{
	char	padchar;

	if (len >= formatinfo->width)
		return ;
	if (formatinfo->flags & FLAG_ZERO)
		padchar = '0';
	else
		padchar = ' ';
	out_fill(out, (formatinfo->width - len), padchar);
}

int			print_argument(int fd, t_formatinfo *formatinfo, va_list ap)
{
	void		(*print_func)(t_formatinfo*, va_list, t_output*);
	t_output	output;
	int			output_size;
	va_list		ap2;

	va_copy(ap2, ap);
	print_func = get_func(formatinfo->specifier);
	out_init(&output);
	print_func(formatinfo, ap, &output);
	output_size = output.size;
	out_init(&output);
	output.fd = fd;
	if (formatinfo->flags & FLAG_MINUS)
	{
		print_func(formatinfo, ap2, &output);
		print_space_padding(formatinfo, output_size, &output);
	}
	else
	{
		print_space_padding(formatinfo, output_size, &output);
		print_func(formatinfo, ap2, &output);
	}
	return (output.size);
}
