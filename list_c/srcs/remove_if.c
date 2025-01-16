/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:14:37 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:14:37 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	remove_if_lt(t_list_ptr list, char *val)
{
	t_node	*curr;
	t_node	*tmp;

	if (empty_lt(list))
		return ;
	curr = list->head;
	while (curr)
	{
		tmp = curr->next;
		if (diff_lt(curr->val, val))
			remove_node_lt(list, curr);
		curr = tmp;
	}
}

void	remove_if_range_lt(t_list_ptr list, t_node *start, t_node *end,
		char *val)
{
	t_node	*curr;
	t_node	*tmp;

	if (empty_lt(list))
		return ;
	curr = start;
	while (curr != end)
	{
		tmp = curr->next;
		if (diff_lt(curr->val, val))
			remove_node_lt(list, curr);
		curr = tmp;
	}
}
