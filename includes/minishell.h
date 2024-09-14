/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:25:55 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/14 19:53:13 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <bst.h>
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <libft.h>
# include <list.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_minishell	t_minishell;
typedef t_minishell			*t_minishell_ptr;
typedef struct s_command	t_command;
typedef t_command			*t_command_ptr;
typedef struct s_cmd_matrix	t_cmd_matrix;
typedef t_cmd_matrix		*t_cmd_matrix_ptr;

struct						s_minishell
{
	t_list_ptr				line;
	t_BST_ptr				env;
	t_cmd_matrix_ptr		commands;
};

struct						s_command
{
	t_minishell_ptr			minishell;
	char					*name;
	t_list					args;
	t_list					options;
};

struct						s_cmd_matrix
{
	t_minishell_ptr			minishell;
	t_command_ptr			*cmds;
	int						size;
};

t_minishell_ptr				init_minishell(char **env);
void						clear_minishell(t_minishell_ptr *minishell);

// tokenizing
void						tokenize(t_minishell_ptr minishell, char *delim,
								char *input);

// quotes_check
bool						ft_quotes_check(t_list_ptr line);

// remove_spaces
void						ft_remove_spaces(t_list_ptr line);

// helpers
bool						is_quote(char ch);

// append
void						ft_append(char **left, char *right);

// check_builtin
bool						is_builtin(const char *val);

// cmds_count
void						ft_count_cmds (t_minishell_ptr minishell);

// cmds_utils
t_cmd_matrix_ptr			init_cmds(t_minishell_ptr minishell);
void						clear_cmds(t_cmd_matrix_ptr commands);
void						get_cmds(t_minishell_ptr minishell);

#endif // MINISHELL_H
