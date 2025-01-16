/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:17:36 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:17:36 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int	size_from_head_lt(t_node_ptr head)
{
	int	size;

	size = 0;
	while (head)
	{
		head = head->next;
		++size;
	}
	return (size);
}

int	get_size(t_list_ptr list)
{
	return (list->size);
}
