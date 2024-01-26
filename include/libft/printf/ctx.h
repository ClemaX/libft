#pragma once

#include <stdarg.h>

#include <libft/printf/line.h>

typedef struct	s_pf_ctx
{
	const char	*fmt;
	va_list		ap;
	t_line		*line;
}				t_pf_ctx;
