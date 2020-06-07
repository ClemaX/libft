#ifndef PARSE_H
# define PARSE_H

# include <stdarg.h>
# include <libft.h>
# include <printf/specs.h>
# include <printf/line.h>


t_line	*parse_fmt(const char *fmt, va_list ap);

#endif
