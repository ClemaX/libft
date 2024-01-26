#pragma once

#include <stdarg.h>

typedef struct	s_sf_ctx
{
	const char	*fmt;
	va_list		ap;
}				t_sf_ctx;
