#pragma once

#ifndef PRIuOFF_T
# ifdef __APPLE__
# define PRIuOFF_T "%llu"
# define PRIxOFF_T "%llx"
# else
# define PRIuOFF_T "%lu"
# define PRIxOFF_T "%lx"
# endif
#endif

int ft_printf(const char *fmt, ...)
    __attribute__((format(printf,1,2)));

int ft_dprintf(int fd, const char *fmt, ...)
    __attribute__((format(printf,2,3)));
