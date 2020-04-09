/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:18:06 by lutsiara          #+#    #+#             */
/*   Updated: 2020/03/10 15:22:26 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define BUFF_SIZE 100

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_list
{
	void			*content;
	unsigned long	content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_dlist
{
	void			*content;
	unsigned long	content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

int				ft_printf(const char *format, ...);
int				ft_fprintf(int fd, const char *format, ...);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);

int				get_next_line(const int fd, char **line);

void			*ft_memset(void *ptr, int value, unsigned long num);
void			*ft_memcpy(void *dst, const void *src, unsigned long num);
void			ft_bzero(void *s, int n);
void			*ft_memccpy(void *dest, const void *src, \
				int c, unsigned long n);
void			*ft_memmove(void *dst, const void *src, unsigned long num);
void			*ft_memchr(const void *ptr, int value, unsigned long num);
int				ft_memcmp(const void *ptr1, \
				const void *ptr2, unsigned long num);
void			*ft_realloc(void *ptr, unsigned long size);

unsigned long	ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, unsigned int n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strdup(const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, int nb);
unsigned long	ft_strlcat(char *dest, \
				const char *src, unsigned int size);
char			*ft_strchr(const char *str, int character);
char			*ft_strrchr(const char *str, int character);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *big, \
				const char *little, unsigned long len);

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isascii(int c);

int				ft_tolower(int c);
int				ft_toupper(int c);

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

void			*ft_memalloc(unsigned long size);
void			*ft_safe_malloc(unsigned long size);
void			ft_memdel(void **ap);

void			ft_strclr(char *s);
char			*ft_strnew(unsigned long size);
void			ft_strdel(char **as);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, unsigned long n);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, \
				unsigned int start, unsigned long len);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, \
				unsigned int start, unsigned long len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *str, char c);

t_list			*ft_lstnew(void const *content, unsigned long content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, unsigned long));
void			ft_lstdel(t_list **alst, void (*del)(void*, unsigned long));
void			ft_lstadd(t_list **alst, t_list *_new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lst_del(t_list **lst);
void			ft_lstadd_last(t_list **alst, t_list *n);
t_list			*ft_lst_del_one(t_list *curr, void *value, unsigned long size);
t_list			*ft_lstnewchar(void const *content, unsigned long content_size);
void			ft_lstrev(t_list **list);

t_dlist			*ft_dlstnew(void const *content, unsigned long content_size);
void			ft_dlstdelone(t_dlist **alst, \
				void (*del)(void*, unsigned long));
void			ft_dlstdel(t_dlist **alst, void (*del)(void*, unsigned long));
void			ft_dlstadd(t_dlist **alst, t_dlist *_new);
void			ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
t_dlist			*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem));
t_dlist			*ft_dlstfirst(t_dlist *lst);

void			ft_foreach(void *ptr, int size, int step, void (f)(void*));
int				ft_any(void *ptr, int size, int step, int (f)(void*));
int				ft_all(void *ptr, int size, int step, int (f)(void*));
int				ft_min(int *ptr, int size);
int				ft_max(int *ptr, int size);

double			ft_powf(double num, int e);
int				ft_abs(int val);
unsigned int	ft_digitlen(long long n, unsigned int base);

#endif
