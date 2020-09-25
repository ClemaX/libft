/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:29:38 by chamada           #+#    #+#             */
/*   Updated: 2020/09/25 14:52:33 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <term/term.h>

static int	handle_status(t_term *t, int status)
{
	if (status & TERM_INT)
		status = term_cancel(t);
	if (status & TERM_EOF && t->line->length == 0)
		status &= ~TERM_READING;
	if (status & TERM_NEWLINE)
		status = term_new_line(t, status);
	if (status & TERM_CLEAR)
		term_clear_screen(t, status);
	if (status & TERM_STOP)
		term_stop(t);
	if (status & TERM_ERASE)
		status = term_erase(t, status);
	return ((status & (~TERM_CONSUME & ~TERM_NEWLINE)));
}

void	term_write_prompt(t_term *t, int status)
{
	if (status & TERM_WAITING)
		term_prewrite(t, "> ", 2);
	else
		term_prewrite(t, TERM_PS1, sizeof(TERM_PS1) - 1);
}

int			term_prompt(int ac, const char **av, const char **envp,
	int (*exec)(const char*, t_term*))
{
	int		status;
	t_term	term;

	(void)ac;
	if (!(term.name = ft_basename(av[0])))
		return (-1);
	status = TERM_READING;
	if (!term_init(&term, envp, exec))
		return (-1);
	term_write_prompt(&term, status);
	tputs(term.caps.insert, 0, &ft_putchar);
	while (status & TERM_READING)
		status = handle_status(&term, term_read(&term, status));
	if (term_destroy(&term) == -1)
		status |= TERM_ERROR;
	tputs(term.caps.insert_end, 0, &ft_putchar);
	write(1, "exit\n", 5);
	return ((status & TERM_ERROR) ? -1 : term.st);
}