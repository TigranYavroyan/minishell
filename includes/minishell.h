/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:25:55 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/23 22:00:06 by tyavroya         ###   ########.fr       */
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
# include <limits.h>

# define UNUSED __attribute__((unused))
# define DTOR __attribute__((destructor))
# define INV_OPTION 2
# define INV_ARG 1
# define CMD_NOT_FOUND 127
# define DIR_ERROR 126
# define SYNTAX_ERROR 258

typedef struct s_minishell	t_minishell;
typedef t_minishell			*t_minishell_ptr;
typedef struct s_command	t_command;
typedef t_command			*t_command_ptr;
typedef struct s_cmd_matrix	t_cmd_matrix;
typedef t_cmd_matrix		*t_cmd_matrix_ptr;

struct						s_command
{
	t_minishell_ptr			minishell;
	char					*name;
	t_list_ptr				args;
	t_list_ptr				options;
};

struct						s_minishell
{
	t_list_ptr				line;
	t_BST_ptr				env;
	t_BST_ptr				export;
	t_cmd_matrix_ptr		commands;
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
void						remove_2d_str (char** str);
void						ft_err_msg(char *msg);
void						__exit__(const char* name, const char* err);

// append
void						ft_append(char **left, char *right);

// check_builtin
bool						is_builtin(const char *val);

// cmds_count
void						ft_count_cmds(t_minishell_ptr minishell);

// cmds_utils
t_cmd_matrix_ptr			init_cmds(t_minishell_ptr minishell);
void						clear_cmds(t_cmd_matrix_ptr commands);
void						init_cmd(t_cmd_matrix_ptr cmds);

// get_cmds
void						get_cmds(t_minishell_ptr minishell);

// pipe_check
bool						pipe_check(t_list_ptr line);

// execute
void						execute(t_minishell_ptr minishell);

// exec_builtin
void						exec_builtin(t_command_ptr command);

// echo
void						ft_echo(t_command_ptr command);

// cd
void						ft_cd(t_command_ptr command);

// pwd
void						ft_pwd(t_command_ptr command);

// export
void						ft_export(t_command_ptr command);

// unset
void						ft_unset(t_command_ptr command);

// env
void						ft_env(t_command_ptr command);

// exit
void						ft_exit(t_command_ptr command);

// get_cmd_path
bool						access_cmd(t_command_ptr command);

// sort_env
void						sort_env (char** env);

// is_var_name
bool						is_var_name (char* s, char* e);

// log_in_file
void						log_in_file (char* input);
void						log_header_in_file ();

#endif // MINISHELL_H
