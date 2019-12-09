/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 23:24:01 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:13:36 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef unsigned long	t_size;

typedef	struct			s_list
{
	void			*content;
	struct s_list	*next;
}						t_list;

void					*ft_memset(void *b, int c, t_size len);
void					ft_bzero(void *s, t_size n);
void					*ft_memcpy(void *dst, const void *src, t_size n);
void					*ft_memccpy(void *dst, const void *src, int c,
	t_size n);
void					*ft_memmove(void *dst, const void *src, t_size len);
void					*ft_memchr(const void *s, int c, t_size n);
int						ft_memcmp(const void *s1, const void *s2, t_size n);
t_size					ft_strlen(const char *s);
void					*ft_calloc(t_size count, t_size size);
char					*ft_strdup(const char *s1);
t_size					ft_strlcpy(char *dst, const char *src, t_size size);
t_size					ft_strlcat(char *dst, const char *src, t_size size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
int						ft_strpos(const char *s, int c);
char					*ft_strnstr(const char *haystack, const char *needle,
	t_size len);
int						ft_strncmp(const char *s1, const char *s2, t_size n);
int						ft_isupper(int c);
int						ft_islower(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isspace(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_issign(int c);
int						ft_atoi(const char *str);
int						ft_toupper(int c);
int						ft_tolower(int c);

char					*ft_substr(char const *s, unsigned int start,
	t_size len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_strmapi
	(char const *s, char (*f)(unsigned int, char));
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						ft_numlen(unsigned long long n, unsigned base);
long double				ft_pow(int nb, int pow);

t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **alst, t_list *new);
t_list					*ft_lstlast(t_list *lst);
int						ft_lstsize(t_list *lst);
void					ft_lstadd_back(t_list **alst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void*));
void					ft_lstiter(t_list *lst, void (*f)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void*));
t_list					*ft_lstmap
	(t_list *lst, void *(*f)(void*), void (*del)(void*));
int						get_next_line(int fd, char **line);
int						ft_printf
	(const char *fmt, ...) __attribute__((format(printf,1,2)));
int						ft_sscanf
	(const char *src, const char *fmt, ...) __attribute__((format(scanf,2,3)));

#endif
