/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:25:50 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/29 17:34:36 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef enum		e_rank
{
	NOTHING,
	ROOM,
	LINK,
	NBANTS,
	COMMENT,
	COMMAND
}					t_rank;

typedef struct		s_links
{
	struct s_graph	*room;
	struct s_links	*next;
}					t_links;

typedef struct		s_graph
{
	unsigned int	nb_ants;
	t_links			*links;
	unsigned char	state;
	char			*name;
	long			x;
	long			y;
}					t_graph;

typedef struct		s_path
{
	t_graph			*room;
	struct s_path	*next;
}					t_path;

typedef struct		s_container
{
	t_path			*path;
	unsigned int	len;
}					t_container;

typedef struct		s_ctnl
{
	t_container		*path_box;
	struct s_ctnl	*next;
}					t_ctnl;

t_graph				*ft_alloc_room(void);
t_links				*ft_alloc_link(void);
t_path				*ft_alloc_path_elem(void);
t_container			*ft_alloc_container_elem(void);
t_ctnl				*ft_alloc_ctnl_elem(void);

int					ft_set_room(t_graph **room, char *name, long x, long y);
int					ft_set_link(t_links **elem, t_graph *room);
int					ft_set_path_elem(t_path **elem, t_graph *room);
int					ft_set_container(t_container **box, t_path *path);
int					ft_set_ctnl(t_ctnl **elem, t_container *box);

int					ft_enqueue_room(t_path **path, t_path *elem);
int					ft_enqueue_link(t_links **links, t_links *elem);
int					ft_enqueue_path(t_ctnl **paths, t_ctnl *elem);

int					ft_del_path(t_path **path, unsigned int room);
int					ft_del_container(t_ctnl **paths, unsigned int path);
int					ft_del_graph(t_graph **graph, t_graph *prev_room);
int					ft_del_room(t_graph **room);
int					ft_del_links(t_links **links);

t_graph				*ft_get_graph(void);
int					ft_error(unsigned int func, ...);
t_rank				ft_rank_line(char *line);
int					ft_control_tube_name(char *line, t_path *rooms);
t_graph				*ft_find_room(t_path *rooms);
int					ft_link_rooms(t_path *rooms, char *room1, char *room2);
int					ft_set_start(t_graph *room);
int					ft_set_end(t_graph *room);
int					ft_are_end_start_exist(t_path *rooms);
int					ft_are_rooms_linked(t_graph *start);
int					ft_is_there_path(t_graph *start, t_graph *end);

#endif
