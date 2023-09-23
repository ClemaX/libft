#include <libft/types.h>
#include <libft/numbers.h>

int	ft_base_id(const char *restrict *str, int base)
{
	while (ft_isspace(**str))
		++(*str);
	if (base == 8 && **str == '0')
		++(*str);
	if (base == 16
		&& (*str)[0] == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X'))
		str += 2;
	if (base == 0)
	{
		base = 10;
		if (**str == '0')
		{
			++(*str);
			base = 8;
			if (**str == 'x' || **str == 'X')
			{
				++(*str);
				base <<= 1;
			}
		}
	}
	return base;
}
