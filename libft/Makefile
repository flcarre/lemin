# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:06:41 by lutsiara          #+#    #+#              #
#    Updated: 2020/03/10 15:20:16 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra
CC = gcc $(FLAGS)
SRC_PATH = srcs/
OBJ_PATH = srcs/
INC_PATH = includes/
INC = -I
INCLUDES = $(INC_PATH)
SRC_SUFFIX = .c
H_SUFFIX = .h

H_FILENAME = libft \
			 ft_printf_types \
			 ft_printf

C_FILENAME = ft_abs \
			 ft_all \
			 ft_any \
			 ft_atoi \
			 ft_bzero \
			 ft_dlstadd \
			 ft_dlstdel \
			 ft_dlstdelone \
			 ft_dlstfirst \
			 ft_dlstiter \
			 ft_dlstmap \
			 ft_dlstnew \
			 ft_foreach \
			 ft_fprintf \
			 ft_isalnum \
			 ft_isalpha \
			 ft_isascii \
			 ft_isdigit \
			 ft_islower \
			 ft_isprint \
			 ft_isspace \
			 ft_isupper \
			 ft_itoa \
			 ft_lst_del \
			 ft_lst_del_one \
			 ft_lstadd \
			 ft_lstadd_last \
			 ft_lstdel \
			 ft_lstdelone \
			 ft_lstiter \
			 ft_lstmap \
			 ft_lstnew \
			 ft_lstnewchar \
			 ft_lstrev \
			 ft_max \
			 ft_memalloc \
			 ft_memccpy \
			 ft_memchr \
			 ft_memcmp \
			 ft_memcpy \
			 ft_memdel \
			 ft_memmove \
			 ft_memset \
			 ft_min \
			 ft_powf \
			 ft_putchar \
			 ft_putchar_fd \
			 ft_putendl \
			 ft_putendl_fd \
			 ft_putnbr \
			 ft_putnbr_base \
			 ft_putnbr_fd \
			 ft_putnstr \
			 ft_putstr \
			 ft_putstr_fd \
			 ft_realloc \
			 ft_safe_malloc \
			 ft_strcat \
			 ft_strchr \
			 ft_strclr \
			 ft_strcmp \
			 ft_strcpy \
			 ft_strdel \
			 ft_strdup \
			 ft_strequ \
			 ft_striter \
			 ft_striteri \
			 ft_strjoin \
			 ft_strlcat \
			 ft_strlen \
			 ft_strmap \
			 ft_strmapi \
			 ft_strncat \
			 ft_strncmp \
			 ft_strncpy \
			 ft_strnequ \
			 ft_strnew \
			 ft_strnstr \
			 ft_strrchr \
			 ft_strsplit \
			 ft_strstr \
			 ft_strsub \
			 ft_strtrim \
			 ft_tolower \
			 ft_toupper \
			 get_next_line \
			 out_fill \
			 out_init \
			 out_putchar \
			 out_putchar_len \
			 parse_flags \
			 parse_length \
			 parse_number \
			 parse_precision \
			 parse_specifier \
			 parse_width \
			 print_argument \
			 print_char \
			 print_float \
			 print_hex \
			 print_hexup \
			 print_int \
			 print_number_generic \
			 print_octal \
			 print_padding \
			 print_percent \
			 print_prepound_notnull \
			 print_ptr \
			 print_str \
			 print_uint \
			 read_argument \
			 value_is_zero

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

$(NAME): $(OBJ) $(H_FILES) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\r$(EOLCLR)$(NAME): $(GREEN)$(OK)\n"

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\r$(EOLCLR)$(NAME): $< $(BLUE)$(OK)"
	@$(CC) -o $@ -c $< $(HEADER) $(FLAGS)

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
