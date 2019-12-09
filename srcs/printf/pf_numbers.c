/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_numbers.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 17:08:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 16:51:59 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <printf/numbers.h>
#include <printf/specs.h>

/*
**	n:	The number
**	s:	The format specification
**
**	Set the numbers dimensions according to its length using the format
**	specification
**	Note: The prefix_len includes the sign
*/

void		parse_dimensions(t_number *n, t_spec s)
{
	int	size;

	n->len = (!n->value && !s.precision) ? 0 : ft_numlen(n->value, n->radix);
	if (s.precision > n->len)
		n->len = s.precision;
	n->prefix = '\0';
	n->prefix_len = (n->sign != '\0');
	if (s.flags & HASH)
	{
		if (n->radix == R_HEX && (n->value || s.type == PTR))
		{
			n->prefix = (s.type == LHEX || s.type == PTR) ? 'x' : 'X';
			n->prefix_len += 2;
		}
		else if (n->radix == R_OCT)
			n->prefix_len += !s.precision || (s.precision == -1 && n->value);
	}
	size = s.width - n->prefix_len;
	if ((s.flags & ZERO) && s.precision == -1 && size > n->len)
		n->len = size;
	size = n->len + n->prefix_len;
	n->padding = (s.width > size) ? s.width - size : 0;
}

/*
**	ap:		The variadic arguments list
**	spec:	The format specification
**
**	Parse a given number depending on its type specification
**	Note: The RADIXES and DIGITS lists must be sorted
*/

t_number	parse_number(va_list ap, t_spec spec)
{
	const int	radixes[RADIX_N] = RADIXES;
	const char	*digits[RADIX_N] = DIGITS;
	t_number	number;

	if (spec.type == DEC || spec.type == INT)
		number = convert_signed(ap, spec);
	else
		number = convert_unsigned(ap, spec);
	number.radix = radixes[spec.type - PTR];
	number.digits = digits[spec.type - PTR];
	parse_dimensions(&number, spec);
	return (number);
}
