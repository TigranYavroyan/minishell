/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:07 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:20:07 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	parse_dollar(t_minishell_ptr minishell)
{
	t_node_ptr		curr;
	t_value_type	begin;

	curr = minishell->line->head;
	while (curr)
	{
		begin = ft_strchr(curr->val, '$');
		if (begin)
		{
			ft_dollar_resolution(minishell, curr, begin + 1, &curr->val);
			if (curr->val && !(*curr->val))
				curr = remove_node_lt(minishell->line, curr);
			else
				curr = curr->next;
		}
		else
			curr = curr->next;
	}
}

void	remove_spaces(t_list_ptr line, t_set_ptr quote_tracker)
{
	t_node_ptr	curr;

	curr = line->head;
	while (curr)
	{
		if (ft_isspace(*curr->val) && !find_set(quote_tracker, curr))
			curr = remove_node_lt(line, curr);
		else
			curr = curr->next;
	}
}
