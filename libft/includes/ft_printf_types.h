/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:07:02 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 19:43:54 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

# include <unistd.h>

typedef struct s_formatinfo		t_formatinfo;
typedef enum e_specifier		t_specifier;
typedef enum e_length			t_length;
typedef struct s_output			t_output;

typedef	unsigned char			t_u8;
typedef	unsigned short			t_u16;
typedef	unsigned int			t_u32;
typedef	unsigned long long		t_u64;

typedef	char					t_8;
typedef	short					t_16;
typedef	int						t_32;
typedef	long long				t_64;

typedef char					t_s8;
typedef short					t_s16;
typedef int						t_s32;
typedef	long					t_s64;
typedef float					t_f32;
typedef double					t_f64;

# define SPEC_COUNT 11

enum							e_specifier
{
	SPEC_NONE,
	SPEC_INT,
	SPEC_UINT,
	SPEC_OCTAL,
	SPEC_HEX,
	SPEC_HEXUP,
	SPEC_FLOAT,
	SPEC_STR,
	SPEC_CHAR,
	SPEC_PERCENT,
	SPEC_PTR,
};

enum							e_length
{
	NONE,
	LEN_CHAR,
	LEN_SHORT,
	LEN_LONG,
	LEN_LLONG,
	LEN_PTR,
};

struct							s_formatinfo
{
	int			precision;
	int			width;
	t_length	length;
	t_specifier	specifier;
	char		flags;
};

struct							s_output
{
	int				fd;
	unsigned long	size;
	char			*buf;
};

#endif
