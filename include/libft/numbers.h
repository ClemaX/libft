#pragma once

#include <stdint.h>

#ifndef BASE36_CHARSET
# define BASE36_CHARSET "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#endif

char		*ft_itoa(int n);
int			ft_snitoa(char *dest, int n, int size);

unsigned	ft_numlen(uintmax_t n, unsigned base);
long double	ft_pow(int nb, int pow);
int			ft_atoi(const char *str);
long		ft_strtol(const char *restrict str, const char **restrict end, int base);
int			ft_base_id(const char *restrict *str, int hint);
