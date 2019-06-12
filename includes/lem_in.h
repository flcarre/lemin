/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:25:50 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/12 23:18:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define SIZE_HASH_TABLE 500000

typedef enum		e_rank
{
	NOTHING,
	ROOM,
	LINK,
	NBANTS,
	COMMENT,
	COMMAND,
	START,
	END
}					t_rank;

typedef struct		s_hash
{
	struct s_links	*hash;
	int				*dist;
	struct s_hash	*next;
}					t_hash;

typedef struct		s_links
{
	struct s_graph	*room;
	struct s_links	*prev;
	struct s_links	*next;
}					t_links;

typedef struct		s_graph
{
	unsigned int	nb_ants;
	unsigned int	id_ants;
	int				dist;
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

typedef struct		s_ctn
{
	t_path			*path;
	int				len;
	struct s_ctn	*next;
}					t_ctn;

typedef struct		s_var
{
	unsigned int	nb_ants;
	unsigned char	state;
	t_graph			*start;
	t_graph			*end;
	t_graph			*room1;
	t_graph			*room2;
	t_path			*queue;
	t_path			*ptr;
	t_ctn			*paths;
	t_links			*dij;
	t_hash			*hash;
	t_links			**hash_name;
	t_links			**hash_addr;

}					t_var;

char				*ft_gnl(unsigned char mode);

t_graph				*ft_alloc_room(void);
t_links				*ft_alloc_link(void);
t_path				*ft_alloc_path_elem(void);
t_ctn				*ft_alloc_ctn_elem(void);

int					ft_del(t_var *var);
int					ft_del_links(t_links **links);
int					ft_del_room(t_graph **room);
int					ft_del_ctn(t_ctn **paths);
int					ft_del_path(t_path **path, unsigned int room);

int					ft_enqueue_room(t_path **path, t_path *elem);
int					ft_push_room(t_path **path, t_path *elem);
int					ft_push_link(t_links **links, t_links *elem);
int					ft_push_path(t_ctn **paths, t_ctn *elem);

int					ft_push_hash(t_var *var, t_graph *room);
int					ft_push_hash2(t_var *var, t_graph *room);
t_graph				*ft_return_room(t_var *var, char *name);
t_links				*ft_return_link(t_var *var, t_graph *room);
t_links				*ft_pop_hash(t_hash **hash);
int					ft_order_hash(t_hash **hash, t_hash *elem);
t_hash				*ft_new_hash(t_links *hash_addr, int *dist);

t_rank				ft_rank_line(char *line);
t_rank				ft_isvalidcmd(char *line);
int					ft_get_graph(t_var *var);
int					ft_get_ants(unsigned int *nb_ants);
int					ft_set_room(t_graph **room, char *line, t_var *var);
int					ft_create_rooms(t_var *var);
int					ft_control_names(char *line, t_var *var);
int					ft_make_links(t_var *var);
int					ft_make_link(char *line, t_var *var);
int					ft_checkup(t_var *var);

t_ctn				*ft_dijkstra(t_var *var, int i);

int					ft_reset(t_graph *start, unsigned char state);
int					ft_set(t_graph *start, unsigned char state);

#endif
