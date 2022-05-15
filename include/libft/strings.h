#pragma once

#include <stddef.h>

typedef void	(t_striter_fun(char c));
typedef char	(t_strmapi_fun(unsigned i, char c));

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *a);
char			*ft_strndup(const char *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strpos(const char *s, int c);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
int				ft_strncmp(const char *a, const char *b, size_t n);
int				ft_strcmp(const char *a, const char *b);
int				ft_strcmpi(const char *a, const char *b);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strmapi(char const *s, t_strmapi_fun *fun);
void			ft_striter(char *str, t_striter_fun *fun);

char			*ft_strjoin(char const *a, char const *b);
char			*ft_strtrim(char const *a, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strtok(char *restrict str, const char *restrict delim);

void			*strs_unload_n(char **strs, int n);
void			*strs_unload(char **strs);
void			strs_print(char **strs);
