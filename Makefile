# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 17:54:03 by lutsiara          #+#    #+#              #
#    Updated: 2019/05/06 14:50:23 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = libft/

EXEC = srcs/

LIBFT = libft/libft.a

export LIBFT NAME

all:
	@make -C $(LIB)
	@make -C $(EXEC)

clean:
	@make -C $(LIB) clean
	@make -C $(EXEC) clean
	@echo "rm *.o\033[0;32m ✓\033[0m"

fclean: clean
	@make -C $(LIB) fclean
	@make -C $(EXEC) fclean
	@echo "rm $(LIBFT)\033[0;32m ✓\033[0m"
	@echo "rm $(NAME)\033[0;32m ✓\033[0m"

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
