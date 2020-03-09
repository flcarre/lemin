/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:25:50 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/09 13:55:43 by lutsiara         ###   ########.fr       */
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

typedef struct		s_matrix
{
	struct s_graph	*room;
	struct s_graph	*link;
	struct s_graph	*follow;
	struct s_matrix	*address;
	struct s_matrix	*address_follow;
	int				value;
}					t_matrix;

typedef struct		s_graph
{
	unsigned int	nb_ants;
	unsigned int	nb_links;
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
	unsigned int	id_ant;
	struct s_ctn	*ant;
	unsigned int	ants;
	struct s_ctn	*next;
}					t_ctn;

typedef struct		s_var
{
	unsigned int	nb_rooms;
	unsigned int	nb_ants;
	unsigned int	nb_path;
	unsigned int	nb_bfs;
	unsigned int	max_nb_path;
	unsigned int	nb_travel;
	unsigned int	cycle;
	unsigned char	state;
	t_graph			*start;
	t_graph			*end;
	t_graph			*room1;
	t_graph			*room2;
	t_path			*queue;
	t_path			*ptr;
	t_ctn			*ants;
	t_ctn			*paths;
	t_ctn			*bfs;
	t_ctn			*travel;
	t_links			*dij;
	t_links			*list;
	t_links			*file;
	t_matrix		**residual_matrix;
	t_matrix		*parent;
	t_matrix		*visited;
	t_hash			*hash;
	t_links			**hash_name;
	t_links			**hash_addr;
}					t_var;

typedef struct		s_min
{
	unsigned int	min;
	t_ctn			*travel;
	unsigned int	min_cycle;
	unsigned int	sum;
	unsigned int	save;
	unsigned int	ret;
	unsigned int	i;
}					t_min;

char				*ft_gnl(unsigned char mode);

t_graph				*ft_alloc_room(void);
t_links				*ft_alloc_link(void);
t_path				*ft_alloc_path_elem(void);
t_ctn				*ft_alloc_ctn_elem(void);
t_matrix			**ft_alloc_matrix(unsigned int size);

int					ft_del(t_var *var);
int					ft_del_links(t_links **links);
int					ft_del_room(t_graph **room);
int					ft_del_ctn(t_ctn **paths);
int					ft_del_path(t_path **path, unsigned int room);
void				*ft_freematrix(t_matrix ***matrix, unsigned int limit);

int					ft_enqueue_room(t_path **path, t_path *elem);
int					ft_push_room(t_path **path, t_path *elem);
int					ft_push_link(t_links **links, t_links *elem);
int					ft_enqueue_path(t_ctn **paths, t_ctn *elem);
int					ft_push_path(t_ctn **paths, t_ctn *elem);
int					ft_enqueue_link(t_links **list, t_graph *room);
int					ft_order_path(t_ctn **paths, t_ctn *elem);
int					ft_add(t_var *var, t_graph *room, t_ctn *elem);
int					ft_enqueue(t_links **list, t_graph *room);
t_graph				*ft_dequeue(t_links **list);

int					ft_enqueue_ant(t_ctn **stack, t_ctn *ant);
int					ft_repush_ants(t_var *var, t_ctn *ants);
t_ctn				*ft_pop_ant(t_ctn **stack);
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

int					ft_ek_bfs(t_var *var, unsigned int s, unsigned int t);
t_ctn				*ft_edmonds_karp(t_var *var);
t_ctn				*ft_dijkstra(t_var *var);
unsigned int		ft_how_many(t_var *var, unsigned int *x, unsigned char m);
t_ctn				*ft_bfs(t_var *var, unsigned char m);
int					ft_endisnext(t_var *var, t_links *links);
int					ft_cyclecount(t_var *var, t_min *min);
void				ft_moderate_simu(t_var *var, t_ctn *ants, t_min *min);
void				ft_moderate(t_var *var, t_ctn *ants);
int					ft_travel(t_var *var);

int					ft_reset(t_var *var, unsigned char state);
int					ft_set(t_graph *start, unsigned char state);
void				ft_debug(int ac, char **av, t_var *var);

unsigned int		ft_return_index(t_matrix *array, char *name, \
					unsigned int size);
void				ft_fill_matrix(t_matrix **matrix, t_graph *parent, \
					unsigned int size);
t_matrix			*ft_return_next_room(t_var *var, t_matrix *cell);
void				ft_init_visited(t_var *var);
int					ft_build_ek_path(t_var *var, t_ctn **paths, \
					t_matrix *cell_to);
int					ft_build_ek_paths(t_ctn **paths, t_var *var);
void				*ft_freematrix(t_matrix ***matrix, unsigned int limit);
t_matrix			**ft_alloc_matrix(unsigned int size);
void				ft_fill_matrix(t_matrix **matrix, t_graph *parent, \
					unsigned int size);
t_matrix			**ft_build_matrix(t_var *var, unsigned int size);
t_matrix			*ft_build_array(t_var *var, unsigned int size);

#endif
