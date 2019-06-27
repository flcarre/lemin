# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 17:54:03 by lutsiara          #+#    #+#              #
#    Updated: 2019/06/27 00:34:01 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../lem-in

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCDIR = ./

INCDIR = ../includes/

LIB = ../libft/

INCLIB = ../libft/includes/

SRCS = $(SRCDIR)main.c \
	   $(SRCDIR)ft_gnl.c \
	   $(SRCDIR)ft_alloc.c \
	   $(SRCDIR)ft_enqueue.c \
	   $(SRCDIR)ft_rank_line.c \
	   $(SRCDIR)ft_isvalidcmd.c \
	   $(SRCDIR)ft_get_ants.c \
	   $(SRCDIR)ft_get_graph.c \
	   $(SRCDIR)ft_set_room.c \
	   $(SRCDIR)ft_create_rooms.c \
	   $(SRCDIR)ft_control_names.c \
	   $(SRCDIR)ft_make_links.c \
	   $(SRCDIR)ft_checkup.c \
	   $(SRCDIR)ft_rs.c \
	   $(SRCDIR)ft_hash.c \
	   $(SRCDIR)ft_hash_utils.c \
	   $(SRCDIR)ft_dijkstra.c \
	   $(SRCDIR)ft_how_many.c \
	   $(SRCDIR)ft_bfs.c \
	   $(SRCDIR)ft_bfs_utils.c \
	   $(SRCDIR)ft_del.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) ../$(LIBFT)
	@$(CC) -I $(INCDIR) $(FLAGS) $(OBJS) -o $@ ../$(LIBFT)
	@echo "make $(NAME)\033[0;32m ✓\033[0m"

all: $(NAME)

../$(LIBFT):

%.o: %.c $(INCDIR)/lem_in.h
	@$(CC) -o $@ -c $< -I $(INCDIR) -I $(INCLIB) $(FLAGS)

clean:
	@/bin/rm -rf $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
