#include <term/lexer.h>

bool	is_special(char c)
{
	return (ft_strchr(LEX_SPEC, c) != NULL);
}
