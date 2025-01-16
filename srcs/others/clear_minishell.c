/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:19:09 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:19:09 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	clear_minishell(t_minishell_ptr *minishell)
{
	t_minishell_ptr	tmp;

	tmp = *minishell;
	clear_lt((*minishell)->line);
	free((*minishell)->line);
	clear_bst(&(*minishell)->env);
	clear_bst(&(*minishell)->export);
	clear_set((*minishell)->quote_tracker);
	free((*minishell)->quote_tracker);
	clear_cmds((*minishell)->commands);
	free(tmp->commands);
	close(tmp->descriptors->stdin);
	close(tmp->descriptors->stdout);
	close(tmp->descriptors->stderr);
	free(tmp->descriptors);
	free(tmp);
}
