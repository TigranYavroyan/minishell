/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:20:42 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/20 17:32:09 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	_heredoc_end(char **line, int *fd)
{
	auto_free(line);
	close(*fd);
	if (get_status() == 1)
		return (false);
	*fd = open(HEREDOC_FILE, O_RDONLY, FILE_PERM);
	dup2(*fd, STDIN_FILENO);
	return (true);
}

bool	heredoc_handle(t_command_ptr command, int *fds, int i)
{
	char			*line;
	int				fd;
	t_value_type	begin;

	if (i < command->minishell->commands->size - 1)
		fd = fds[out];
	else
		fd = command->descriptors->stdin;
	run_signals(3);
	while (1)
	{
		line = readline("> ");
		if (!line || _equal(line, command->delim) || get_status() == 1)
			break ;
		if (!command->is_delim_quoted)
		{
			begin = ft_strchr(line, '$');
			if (begin)
				ft_dollar_resolution(command->minishell, NULL, begin + 1,
					&line);
		}
		ft_putendl_fd(line, fd);
		auto_free(&line);
	}
	return (_heredoc_end(&line, &fd));
}
