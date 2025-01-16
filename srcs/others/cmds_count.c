/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:12:12 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:12:12 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_count_cmds(t_minishell_ptr minishell)
{
	t_node_ptr	curr;

	curr = minishell->line->head;
	if (curr)
		++minishell->commands->size;
	while (curr)
	{
		if (_equal(curr->val, "|") && !find_set(minishell->quote_tracker, curr))
			++minishell->commands->size;
		curr = curr->next;
	}
}
