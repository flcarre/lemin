# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 16:35:34 by lutsiara          #+#    #+#              #
#    Updated: 2020/04/09 17:04:30 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../lem-in

FLAGS = -Wall -Werror -Wextra
CC = gcc $(FLAGS)
SRC_PATH = ./
OBJ_PATH = ./
INC_PATH = ../includes/
INC = -I
INCLUDES = $(INC_PATH) ../$(INC_LIB_PATH)
LIB = ../$(LIBFT)
SRC_SUFFIX = .c
H_SUFFIX = .h

H_FILENAME = lem_in

C_FILENAME = main \
			 display \
			 lem_in \
			 bfs/run_bfs \
			 bfs/run_bfs_core \
			 bfs/run_bfs_utils \
			 bfs/inter \
			 bfs/inter_utils \
			 glist_utils/ft_glstadd \
			 glist_utils/ft_glstcpy \
			 glist_utils/ft_glstdel \
			 glist_utils/ft_glstdelone \
			 glist_utils/ft_glsthascontent \
			 glist_utils/ft_glstlen \
			 glist_utils/ft_glstnew \
			 glist_utils/ft_glstrev \
			 glist_utils/ft_glstsort \
			 group_utils/ants_distribution \
			 group_utils/group \
			 group_utils/group_build \
			 parser/parse \
			 parser/parse_core \
			 parser/parse_opt_print \
			 parser/parse_opt_print_help \
			 parser/parse_optimizer \
			 parser/parse_utils \
			 parser/parser_opt \
			 room_utils/room \
			 room_utils/room_create_links \
			 route_utils/route \
			 route_utils/route_print \
			 solution_utils/build_solution \
			 solution_utils/solution \
			 solution_utils/solution_print \
			 solution_utils/solution_round \
			 solver_ek/rebuild_routes \
			 solver_ek/solve \
			 solver_ek/solve_utils \
			 array_utils \
			 utils

INC_FILES = $(addsuffix $(H_SUFFIX),$(H_FILENAME))
SRC_FILES = $(addsuffix $(SRC_SUFFIX),$(C_FILENAME))
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_FILES))
HEADER = $(addprefix $(INC), $(INCLUDES))
H_FILES = $(addprefix $(INC_PATH), $(INC_FILES))

BLUE = "\\033[36m"
RED = "\\033[31m"
WHITE = "\\033[0m"
GREEN = "\\033[32m"

EOLCLR = "\\033[0K"
CHECK = "\\xE2\\x9C\\x94"
OK = "$(CHECK)$(WHITE)"

$(NAME): $(OBJ) $(H_FILES) $(SRC) $(LIB)
	@$(CC) $(HEADER) $(OBJ) $(LIB) -o $@
	@printf "\r$(EOLCLR)$(NAME): $(GREEN)$(OK)\n"

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\r$(EOLCLR)$(NAME): $< $(BLUE)$(OK)"
	@$(CC) $(HEADER) -o $@ -c $<

clean:
	@printf "$(NAME): rm *.o"
	@/bin/rm -rf $(OBJ)
	@printf " $(RED)$(OK)\n"

fclean: clean
	@printf "$(NAME): rm $(NAME)"
	@/bin/rm -f $(NAME)
	@printf " $(RED)$(OK)\n"

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
