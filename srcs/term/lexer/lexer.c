#include <term/lexer.h>
#include <term/env.h>

bool	is_special(char c)
{
	return (ft_strchr(LEX_SPEC, c) != NULL);
}
