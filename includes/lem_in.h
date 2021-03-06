/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:32:25 by lutsiara          #+#    #+#             */
/*   Updated: 2020/04/15 22:17:26 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define MAX_NB_SIZE 10

typedef struct s_glist		t_glist;
typedef	struct s_point		t_point;
typedef	struct s_lem_in		t_lem_in;
typedef	struct s_room		t_room;
typedef	enum e_roomtype		t_roomtype;
typedef	struct s_move		t_move;
typedef struct s_round		t_round;
typedef struct s_solution	t_solution;
typedef struct s_route		t_route;
typedef struct s_group		t_group;
typedef struct s_opt		t_opt;
typedef struct s_inter		t_inter;

union		u_generic
{
	void	*content;
	t_room	*room;
	t_route	*route;
	t_group	*group;
	t_round	*round;
	t_move	*move;
	t_glist	*glist;
	t_inter	*inter;
};

struct		s_glist
{
	union u_generic	gen;
	unsigned long	content_size;
	struct s_glist	*next;
};

struct		s_point
{
	int		x;
	int		y;
};

enum		e_roomtype
{
	STANDARD,
	START,
	END,
};

struct		s_opt
{
	t_bool	debug;
	t_bool	print_room;
	t_bool	print_route;
	t_bool	print_groups;
	t_bool	print_nblines;
	t_bool	print_help;
};

struct		s_lem_in
{
	int		total_ants;
	int		max_routes;
	t_room	*start;
	t_room	*end;
	int		room_count;
	t_glist	*rooms;
	t_room	**array_room;
	t_list	*display;
	t_opt	opt;
};

struct		s_room
{
	char		*name;
	int			id;
	t_roomtype	type;
	t_point		pos;
	int			ants;
	int			ant_id;
	t_glist		*links;
	int			links_count;
	t_room		*prev;
	t_room		*next;
	t_bool		visited;
	t_bool		visited2;
};

struct		s_solution
{
	int		round;
	int		route;
	t_dlist	*rounds;
};

struct		s_round
{
	t_dlist	*moves;
};

struct		s_inter
{
	t_room	*room;
	t_inter	*parent;
	int		child_count;
	int		augmentation;
	t_room	*intersection;
};

struct		s_move
{
	int		id_route;
	int		ant_id;
	t_room	*dst;
};

struct		s_route
{
	int		id_route;
	int		len;
	t_glist	*rooms;
};

struct		s_group
{
	int		route_count;
	int		total_rounds;
	int		*ants_distribution;
	t_route	**routes;
};

void		lem_in_init(t_lem_in *lem_in);
void		lem_in_add_room(t_lem_in *lem_in, t_room *room);
void		lem_in_free(t_lem_in *lem_in);
void		lem_in_error();
void		lem_in_remove_room(t_lem_in *lem_in, t_room *room);

t_glist		*ft_glstnew(void const *content, unsigned long content_size);
void		ft_glstdelone(t_glist **alst, void (*del)(void*, unsigned long));
void		ft_glstdel(t_glist **alst, void (*del)(void*, unsigned long));
void		ft_glstadd(t_glist **alst, t_glist *new);
void		ft_glstiter(t_glist *lst, void (*f)(t_glist *elem));
t_glist		*ft_glstmap(t_glist *lst, t_glist *(*f)(t_glist *elem));
void		ft_glstadd_last(t_glist **alst, t_glist *n);
t_glist		*ft_glstcpy(t_glist *src);
t_bool		ft_glsthascontent(t_glist *lst, void *content);
void		ft_glstsort(t_glist *list, int (*cmp)(void*, void*));
int			ft_glstlen(t_glist *list);
void		ft_glstrev(t_glist **list);

void		parse(t_lem_in *lem_in);
void		parse_ants_count(t_lem_in *lem_in, char **line);
void		parse_rooms(t_lem_in *lem_in, char **line);
void		parse_room(t_lem_in *lem_in, char *line, t_roomtype type);
int			read_room_line(t_lem_in *lem_in, char **line, t_roomtype type);
t_bool		parse_is_link(char *line);
void		parse_links(t_lem_in *lem_in, char **line);
void		parse_link(t_lem_in *lem_in, char **line);
int			parse_number_safe(char *s);

t_room		*room_new(char *name, t_roomtype type, int x, int y);
t_room		*room_find_by_name(t_lem_in *lem_in, char *name);
void		room_free(void *content, unsigned long size);
int			room_cmp(void *a, void *b);

void		room_add_link(t_lem_in *lem_in, char *origin, char *target);
void		room_remove_link(t_room *room, t_room *link);

t_route		*run_bfs(t_lem_in *lem_in);

t_route		*extend_nodes_list(t_lem_in *lem_in, t_glist *nodes, \
			t_glist **next_nodes);
t_route		*extend_node(t_lem_in *lem_in, \
			t_inter *node, t_glist **next_nodes);
t_route		*try_finalize_traverse(t_inter *node);
t_inter		*traverse_end(t_lem_in *lem_in, t_inter *node);
t_inter		*traverse(t_lem_in *lem_in, t_inter *node, t_room *dst);

t_bool		can_traverse(t_inter *inter, t_room *dst);
t_bool		in_intersection(t_room *src, t_room *dst);
t_bool		out_intersection(t_room *src, t_room *dst);
t_inter		*go_to_start(t_lem_in *lem_in, t_inter *inter);
void		mark_as_visited(t_inter *inter);

t_inter		*inter_new(t_lem_in *lem_in);
void		inter_del(t_lem_in *lem_in, t_inter *inter);
void		inter_del_list(t_lem_in *lem_in, t_glist **inters);
t_inter		*inter_create_child(t_lem_in *lem_in, \
			t_inter *parent, t_room *room);
void		inter_print(t_inter *inter);
t_route		*inter_to_route(t_inter *inter);

t_route		*route_new();
t_route		*route_build(t_room *start, t_room *second);
void		route_free(void *content, unsigned long size);
t_route		*route_copy(t_route *src);
void		route_print(t_route *route);
void		route_add_node(t_route *route, t_room *room);

t_group		*group_build(t_lem_in *lem_in);
void		group_add_route(t_group *group, t_route *route);
void		group_free(void *content, unsigned long size);
void		group_print(t_group *group);
int			group_rounds_for_route(t_group *group, int index);
void		distribute_ants(t_group *group, int total_ants);

void		solve(t_lem_in *lem_in, t_solution *solution);
void		rebuild_routes(t_lem_in *lem_in, t_route *route);
void		build_solution(t_lem_in *lem_in, t_group *group,
			t_solution *solution);

int			max_routes(t_lem_in *lem_in);

void		print_solution(t_group *group, t_lem_in *lem_in);
t_bool		ant_try_move(t_room *src, t_room *dest, \
			t_solution *solution, int *ants_routes);
t_bool		ant_can_move(t_room *room);

void		solution_init(t_solution *solution);
void		solution_print(t_lem_in lem_in, t_solution *solution);
void		solution_add_round(t_solution *solution);
void		solution_add_move(t_solution *solution, t_room *dst);
void		solution_free(t_solution *solution);
void		round_free(void *content, unsigned long size);

void		ft_free_tab(char ***tab);
int			ft_strindex(const char *str, char c);
int			gnl(t_lem_in *lem_in, const int fd, char **line);
void		print_nodes(t_glist *nodes);
t_bool		is_number(char *s);

void		*glist_to_array(t_glist *list);
void		array_sort(void **array, unsigned long size, \
			int (cmp)(void*, void*));

void		init_opt(t_lem_in *lem_in);
void		printf_help(void);
void		print_unknow();
void		parse_opt(t_lem_in *lem_in, int ac, char **av);
void		parse_arg(char *s, t_lem_in *lem_in);

void		delete_dead_end(t_lem_in *lem_in, t_room *dead_end);
void		parse_optimizer(t_lem_in *lem_in);

void		room_print_extra(t_room *room);
void		lem_in_print_all_rooms(t_lem_in *lem_in);

void		save_output(t_lem_in *lem_in, char *line);
void		print_output(t_lem_in *lem_in);
void		free_saved_output(t_lem_in *lem_in);

#endif
