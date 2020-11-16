/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 07:32:20 by pablo             #+#    #+#             */
/*   Updated: 2020/11/15 15:25:54 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <unistd.h>
# include <stdbool.h>

# include <term/errors.h>

#define PROCESSES_MAX   4096
#define MANAGE          0
#define LAST			0
#define PENULTIMATE		1

typedef struct 			s_process
{
	pid_t				pid;
    int					wstatus;
	char*const*			data;
	struct s_process*	next;
	struct s_process*	prev;
}						t_process;

typedef struct			s_group
{
	t_process*			active_processes;
	t_process*			nil;
	struct s_group*		next;
}						t_group;

typedef struct			s_session
{
	t_group*			groups; // all background processes by group
	t_process			processes[PROCESSES_MAX + 1]; // exec processes
	t_process			*history;
}						t_session;

// new stuff
void            		add_process(t_process* target, t_process* prev, t_process* next);
void            		remove_process(t_process* target);
void            		process_push_front(t_process* process, t_group* group);
t_process*      		new_process(pid_t pid, int wstatus, char*const* data);
void            		group_push_front(t_session* session, t_group* target);
t_group*        		new_group();
t_session*      		start_session();
void            		delete_process(t_process* target);
void            		delete_group(t_group* target);
void            		end_session(t_session* session);
bool            		update_session_history(t_session* session, t_process* update);
bool					update_background(t_session* session, t_process* process);
t_process*				background_find(t_process* target, const char* search_type, t_group* group);
size_t					background_size(t_group* group);
void					force_exit_background(t_session* session);

// old stuff
size_t					suspended_process_nb(t_process* suspended);
bool					is_suspended(int wstatus);
void            		remove_suspended_process(t_process** suspended);
void                	resume_suspended_processes(t_process** suspended);
void					ft_swap(int* a, int* b);
void					update_used_pids(int new, pid_t** used_pids);

#endif
