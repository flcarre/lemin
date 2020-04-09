# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 22:47:08 by lutsiara          #+#    #+#              #
#    Updated: 2020/03/08 20:34:26 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/
LEMIN = srcs/

LIBFT = libft/libft.a
INC_LIB_PATH = libft/includes/

export LIBFT
export INC_LIB_PATH

all:
	@make -C $(LIB)
	@make -C $(LEMIN)

clean:
	@make -C $(LIB) clean
	@make -C $(LEMIN) clean

fclean:
	@make -C $(LIB) fclean
	@make -C $(LEMIN) fclean

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
