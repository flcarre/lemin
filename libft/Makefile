# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:06:41 by lutsiara          #+#    #+#              #
#    Updated: 2019/06/10 18:58:00 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCDIR = ./srcs/

INCDIR = ./includes/

INCFILES = $(INCDIR)libft.h \
		   $(INCDIR)get_next_line.h \
		   $(INCDIR)ft_ieee.h \
		   $(INCDIR)ft_glo_print.h \
		   $(INCDIR)ft_printf.h

SRCS = $(SRCDIR)ft_atoi.c \
	   $(SRCDIR)ft_atoui.c \
	   $(SRCDIR)ft_atol.c \
	   $(SRCDIR)ft_bzero.c \
	   $(SRCDIR)ft_djb2a.c \
	   $(SRCDIR)ft_countword.c \
	   $(SRCDIR)ft_delcontent.c \
	   $(SRCDIR)ft_digitlen.c \
	   $(SRCDIR)ft_isalnum.c \
	   $(SRCDIR)ft_isalpha.c \
	   $(SRCDIR)ft_isascii.c \
	   $(SRCDIR)ft_isdigit.c \
	   $(SRCDIR)ft_islower.c \
	   $(SRCDIR)ft_isprint.c \
	   $(SRCDIR)ft_isspace.c \
	   $(SRCDIR)ft_isupper.c \
	   $(SRCDIR)ft_iswhitespace.c \
	   $(SRCDIR)ft_itoa.c \
	   $(SRCDIR)ft_lstadd.c \
	   $(SRCDIR)ft_lstdel.c \
	   $(SRCDIR)ft_lstdelone.c \
	   $(SRCDIR)ft_lstdup.c \
	   $(SRCDIR)ft_lstdupone.c \
	   $(SRCDIR)ft_lstenqueue.c \
	   $(SRCDIR)ft_lstdequeue_del.c \
	   $(SRCDIR)ft_lstiter.c \
	   $(SRCDIR)ft_lstmap.c \
	   $(SRCDIR)ft_lstnew.c \
	   $(SRCDIR)ft_memalloc.c \
	   $(SRCDIR)ft_memccpy.c \
	   $(SRCDIR)ft_memchr.c \
	   $(SRCDIR)ft_memcmp.c \
	   $(SRCDIR)ft_memcpy.c \
	   $(SRCDIR)ft_memdel.c \
	   $(SRCDIR)ft_memmove.c \
	   $(SRCDIR)ft_memset.c \
	   $(SRCDIR)ft_putchar.c \
	   $(SRCDIR)ft_putchar_fd.c \
	   $(SRCDIR)ft_putendl.c \
	   $(SRCDIR)ft_putendl_fd.c \
	   $(SRCDIR)ft_putnbr.c \
	   $(SRCDIR)ft_putunbr.c \
	   $(SRCDIR)ft_putnbr_fd.c \
	   $(SRCDIR)ft_putstr.c \
	   $(SRCDIR)ft_putstr_fd.c \
	   $(SRCDIR)ft_strcat.c \
	   $(SRCDIR)ft_strchr.c \
	   $(SRCDIR)ft_strclr.c \
	   $(SRCDIR)ft_strcmp.c \
	   $(SRCDIR)ft_strcpy.c \
	   $(SRCDIR)ft_strdel.c \
	   $(SRCDIR)ft_strdup.c \
	   $(SRCDIR)ft_strequ.c \
	   $(SRCDIR)ft_striter.c \
	   $(SRCDIR)ft_striteri.c \
	   $(SRCDIR)ft_strjoin.c \
	   $(SRCDIR)ft_strlcat.c \
	   $(SRCDIR)ft_strlen.c \
	   $(SRCDIR)ft_strmap.c \
	   $(SRCDIR)ft_strmapi.c \
	   $(SRCDIR)ft_strncat.c \
	   $(SRCDIR)ft_strncmp.c \
	   $(SRCDIR)ft_strrevncmp.c \
	   $(SRCDIR)ft_strncpy.c \
	   $(SRCDIR)ft_strnequ.c \
	   $(SRCDIR)ft_strnew.c \
	   $(SRCDIR)ft_strnstr.c \
	   $(SRCDIR)ft_strrchr.c \
	   $(SRCDIR)ft_strsplit.c \
	   $(SRCDIR)ft_strstr.c \
	   $(SRCDIR)ft_chunkcmp.c \
	   $(SRCDIR)ft_strsub.c \
	   $(SRCDIR)ft_strtabdel.c \
	   $(SRCDIR)ft_strtabnew.c \
	   $(SRCDIR)ft_strtrim.c \
	   $(SRCDIR)ft_tolower.c \
	   $(SRCDIR)ft_toupper.c \
	   $(SRCDIR)ft_inttabmax.c \
	   $(SRCDIR)gnl.c \
	   $(SRCDIR)get_next_line.c \
	   $(SRCDIR)ft_iputchar.c \
	   $(SRCDIR)ft_iputxchar.c \
	   $(SRCDIR)ft_iputnbr_base.c \
	   $(SRCDIR)ft_iputunbr_base.c \
	   $(SRCDIR)ft_iputstr.c \
	   $(SRCDIR)ft_iputnstr.c \
	   $(SRCDIR)ft_dmod.c \
	   $(SRCDIR)ft_ldmod.c \
	   $(SRCDIR)ft_dabs.c \
	   $(SRCDIR)ft_ldabs.c \
	   $(SRCDIR)ft_ldfrexp.c \
	   $(SRCDIR)ft_dfrexp.c \
	   $(SRCDIR)ft_ldexp.c \
	   $(SRCDIR)ft_dexp.c \
	   $(SRCDIR)ft_isnan.c \
	   $(SRCDIR)ft_isinf.c \
	   $(SRCDIR)ft_isdigit.c \
	   $(SRCDIR)ft_isspace.c \
	   $(SRCDIR)ft_dclassify.c \
	   $(SRCDIR)ft_signbit.c \
	   $(SRCDIR)ft_iputwchar.c \
	   $(SRCDIR)ft_iputwstr.c \
	   $(SRCDIR)ft_iputnwstr.c \
	   $(SRCDIR)ft_atoui.c \
	   $(SRCDIR)ft_wstrlen.c \
	   $(SRCDIR)ft_wcharlen.c \
	   $(SRCDIR)ft_ld_ldiglen.c \
	   $(SRCDIR)ft_ull.c \
	   $(SRCDIR)ft_udigitlen.c \
	   $(SRCDIR)ft_printf.c \
	   $(SRCDIR)ft_parse.c \
	   $(SRCDIR)ft_converter.c \
	   $(SRCDIR)ft_dorounding.c \
	   $(SRCDIR)ft_idisnull.c \
	   $(SRCDIR)ft_isid.c \
	   $(SRCDIR)ft_isfm.c \
	   $(SRCDIR)ft_iputldnbr.c \
	   $(SRCDIR)ft_simuldnbr.c \
	   $(SRCDIR)ft_pprocess0.c \
	   $(SRCDIR)ft_pprocess1.c \
	   $(SRCDIR)ft_pprocess2.c \
	   $(SRCDIR)ft_pprocess3.c \
	   $(SRCDIR)ft_pprocess4.c \
	   $(SRCDIR)ft_print0.c \
	   $(SRCDIR)ft_print1.c \
	   $(SRCDIR)ft_print2.c \
	   $(SRCDIR)ft_print3.c \
	   $(SRCDIR)ft_printcolor.c \
	   $(SRCDIR)ft_wcalc.c \
	   $(SRCDIR)ft_wprocess0.c \
	   $(SRCDIR)ft_wprocess1.c \
	   $(SRCDIR)ft_wprocess2.c \
	   $(SRCDIR)ft_wprocess3.c \
	   $(SRCDIR)ft_wprocess4.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "make $(NAME)\033[0;32m ✓\033[0m"

all: $(NAME)

%.o: %.c $(INCFILES)
	@$(CC) -o $@ -c $< -I $(INCDIR) $(FLAGS)

clean:
	@/bin/rm -rf $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
