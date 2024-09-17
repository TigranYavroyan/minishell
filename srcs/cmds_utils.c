/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:06:24 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/17 17:33:08 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd_matrix_ptr	init_cmds(t_minishell_ptr minishell)
{
	t_cmd_matrix_ptr commands;

	commands = (t_cmd_matrix_ptr)wrapper_malloc(sizeof(t_cmd_matrix));
	commands->cmds = NULL;
	commands->minishell = minishell;
	commands->size = 0;
	return (commands);
}

void	init_cmd(t_cmd_matrix_ptr cmds)
{
	int	i;

	i = -1;
	cmds->cmds = (t_command_ptr*)wrapper_malloc(sizeof(t_command_ptr) * cmds->size);
	while (++i < cmds->size)
	{
		cmds->cmds[i] = (t_command_ptr)wrapper_malloc(sizeof(t_command));
		cmds->cmds[i]->args = init_lt();
		cmds->cmds[i]->options = init_lt();
		cmds->cmds[i]->minishell = cmds->minishell;
	}

}

static void remove_cmd(t_command_ptr* command)
{
	clear_lt((*command)->args);
	free((*command)->args);
	clear_lt((*command)->options);
	free((*command)->options);
	free((*command)->name);
	free(*command);
	*command = NULL;
}

void	clear_cmds(t_cmd_matrix_ptr commands)
{
	int	i;

	i = -1;
	while (++i < commands->size)
		remove_cmd(commands->cmds + i);
	free(commands->cmds);
	commands->size = 0;
	commands->cmds = NULL;
}
