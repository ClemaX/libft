/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 23:24:01 by chamada           #+#    #+#             */
/*   Updated: 2020/11/04 21:30:21 by chamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# define PATH_DELIM '/'

# ifndef PRIuOFF_T
#  ifdef __APPLE__
#  define PRIuOFF_T "%llu"
#  define PRIxOFF_T "%llx"
#  else
#  define PRIuOFF_T "%lu"
#  define PRIxOFF_T "%lx"
#  endif
# endif

typedef void	(t_striter_fun(char c));
typedef char	(t_strmapi_fun(unsigned i, char c));

typedef	struct	s_list
{
	struct s_list	*next;
	void			*content;
}				t_list;

typedef int		(t_cmp_fun(void *a, void *b));

typedef void	(t_lstadd_fun(t_list **list, t_list *elem));
typedef void	(t_lstinsert_fun(t_list **list, t_list *elem, t_cmp_fun *cmp));

typedef struct	s_map
{
	char			*key;
	size_t			key_size;
	char			*value;
	struct s_map	*next;
}				t_map;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c,
	size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strpos(const char *s, int c);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);

int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isspace(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_issign(int c);
int				ft_iscntrl(int c);

int				ft_toupper(int c);
int				ft_tolower(int c);

char			*ft_substr(char const *s, unsigned int start,
	size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);

void			*strs_unload_n(char **strs, int n);
void			*strs_unload(char **strs);
void			strs_print(char **strs);

char			*ft_basename(const char *path);

char			*ft_itoa(int n);
int				ft_snitoa(char *dest, int n, int size);
char			*ft_strmapi(char const *s, t_strmapi_fun *fun);
void			ft_striter(char *str, t_striter_fun *fun);
void			ft_putchar_fd(char c, int fd);
int				ft_putchar(int c);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_numlen(unsigned long long n, unsigned base);
long double		ft_pow(int nb, int pow);
int				ft_atoi(const char *str);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *elem);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *elem);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
t_list			*ft_lstmap
	(t_list *lst, void *(*f)(void*), void (*del)(void*));
void			ft_lstsort(t_list **lst, t_cmp_fun *cmp);
void			ft_lstsortrev(t_list **lst, t_cmp_fun *cmp);
void			ft_lstinsert(t_list **list, t_list *elem, t_cmp_fun *cmp);
void			ft_lstinsertrev(t_list **list, t_list *elem, t_cmp_fun *cmp);

const char		*map_set(t_map **map, const char *key, const char *value);
t_map			*map_get(t_map *map, const char *key);
void			map_delone(t_map *elem);
t_map			*map_del(t_map *map, const char *key);
void			map_clr(t_map **map);
t_map			*map_load(const char **strs);
char			**map_export(t_map *map);
void			map_sort(t_map **map, int (*cmp)(t_map*, t_map*));
int				map_cmp(t_map *a, t_map *b);

int				get_next_line(int fd, char **line);
int				ft_printf
	(const char *fmt, ...) __attribute__((format(printf,1,2)));
int				ft_dprintf
	(int fd, const char *fmt, ...) __attribute__((format(printf,2,3)));
int				ft_sscanf
	(const char *src, const char *fmt, ...) __attribute__((format(scanf,2,3)));
int				write_bmp(const char *path, const char *buffer,
	int w, int h);

char			*path_cat(char *dest, const char *a, const char *b);

#endif
