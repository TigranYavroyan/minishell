/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:19:21 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 17:43:05 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	update_quote_info(bool *open, char *opened_ch, t_node_ptr curr)
{
	if (is_quote(*curr->val))
	{
		if (!(*open))
		{
			*open = true;
			*opened_ch = *curr->val;
		}
		else if (*opened_ch == *curr->val)
		{
			*open = false;
			*opened_ch = 0;
		}
	}
}

static void	parse_quotes(t_list_ptr line, t_set_ptr quote_tracker)
{
	bool		open;
	char		opened_ch;
	t_node_ptr	curr;

	open = false;
	opened_ch = 0;
	curr = line->head;
	while (curr)
	{
		if (!open)
		{
			if (_equal(curr->val, "$") && curr->next
				&& is_quote(*curr->next->val))
				curr = remove_node_lt(line, curr);
		}
		if (open && *curr->val != opened_ch)
			insert_set(quote_tracker, curr, get_quote_type(opened_ch));
		update_quote_info(&open, &opened_ch, curr);
		curr = curr->next;
	}
}

bool	remove_quotes(t_minishell_ptr minishell)
{
	t_node_ptr	curr;

	parse_quotes(minishell->line, minishell->quote_tracker);
	if (!ft_quotes_check(minishell->line, minishell->quote_tracker))
	{
		__err_msg_prmt__(NULL, "Unclosed quotes", SYNTAX_ERROR);
		return (false);
	}
	curr = minishell->line->head;
	while (curr)
	{
		if (curr->next && is_quote(*curr->val) && is_quote(*curr->next->val))
			insert_node_lt(minishell->line, "", curr);
		if (is_quote(*curr->val) && !find_set(minishell->quote_tracker, curr))
			curr = remove_node_lt(minishell->line, curr);
		else
			curr = curr->next;
	}
	return (true);
}

static bool	__is_mergeable(t_node_ptr curr, t_set_ptr quote_tracker)
{
	if (!curr || !curr->next)
		return (false);
	if (find_set(quote_tracker, curr) && find_set(quote_tracker, curr->next))
		return (true);
	if (find_set(quote_tracker, curr) && is_mergeable_util(curr->next->val))
		return (true);
	if (find_set(quote_tracker, curr->next) && is_mergeable_util(curr->val))
		return (true);
	if (is_mergeable_util(curr->val) && is_mergeable_util(curr->next->val))
		return (true);
	if ((_equal(curr->val, ">") || _equal(curr->val, "<"))
		&& !find_set(quote_tracker, curr) && !find_set(quote_tracker,
			curr->next))
	{
		if (_equal(curr->val, curr->next->val))
			return (true);
	}
	return (false);
}

void	merge_in_quotes(t_list_ptr line, t_set_ptr quote_tracker)
{
	t_node_ptr	curr;

	curr = line->head;
	while (curr && curr->next)
	{
		if (__is_mergeable(curr, quote_tracker))
		{
			ft_append(&curr->val, curr->next->val);
			remove_node_lt(line, curr->next);
		}
		else
			curr = curr->next;
	}
}
