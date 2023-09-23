#include <stdbool.h>
#include <limits.h>
#include <errno.h>

#include <libft/numbers.h>

#include <libft/strings.h>
#include <libft/types.h>

long		ft_strtol(const char *restrict str, const char **restrict end,
	int base)
{
	static const char	*base_chars = BASE36_CHARSET;
	bool				negative;
	int					base_pos;
	long				value;

	value = 0;
	if (base != 0 && (base < 2 || base > 36))
	{
		errno = EINVAL;
		return value;
	}
	errno = 0;
	base = ft_base_id(&str, base);
	negative = *str == '-' || *str == '+';
	if (negative)
		negative = *str++ == '-';
	while (*str != '\0')
	{
		base_pos = ft_strcasepos(base_chars, *str);
		if (base_pos == -1 || base_pos >= base)
			break;
		if (value > (LONG_MAX - negative) / base - base_pos)
		{
			value = LONG_MAX - negative;
			errno = ERANGE;
			break;
		}
		value = value * base + base_pos;
		++str;
	}
	if (negative)
		value = -value;
	if (end != NULL)
		*end = str;
	return value;
}
