/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:25:48 by tyavroya          #+#    #+#             */
/*   Updated: 2024/09/24 17:57:39 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	push_back_lt(t_list_ptr list, char *str)
{
	t_node	*curr;

	if (list->head == NULL)
	{
		list->head = make_node(str);
		list->tail = list->head;
	}
	else
	{
		curr = make_node(str);
		list->tail->next = curr;
		curr->prev = list->tail;
		list->tail = curr;
	}
	++(list->size);
}

void	push_back_move_lt(t_list_ptr list, char *str)
{
	t_node	*curr;

	if (list->head == NULL)
	{
		list->head = make_node_move(str);
		list->tail = list->head;
	}
	else
	{
		curr = make_node_move(str);
		list->tail->next = curr;
		curr->prev = list->tail;
		list->tail = curr;
	}
	++(list->size);
}

void	push_front_lt(t_list_ptr list, char *str)
{
	t_node	*curr;

	if (list->head == NULL)
	{
		list->head = make_node(str);
		list->tail = list->head;
	}
	else
	{
		curr = make_node(str);
		list->head->prev = curr;
		curr->next = list->head;
		list->head = curr;
	}
	++(list->size);
}

void	insert_node_lt(t_list_ptr list, char *str, t_node *pos)
{
	t_node	*to_insert;

	if (!str || !pos || !list)
		return ;
	if (empty_lt(list) || pos == list->tail)
		push_back_lt(list, str);
	else
	{
		to_insert = make_node(str);
		pos->next->prev = to_insert;
		to_insert->next = pos->next;
		pos->next = to_insert;
		to_insert->prev = pos;
	}
	list->size++;
}

void	move_back_lt(t_list_ptr* left, t_list_ptr right)
{
	if (empty_lt(right))
		return ;
	else if (empty_lt(*left))
	{
		free(*left);
		*left = copy_lt(right); // potential leaks
	}
	else
	{
		(*left)->tail->next = right->head;
		(*left)->tail = right->tail;
		(*left)->size += right->size;
		right->tail = NULL;
		right->head = NULL;
		right->size = 0;
	}
}
