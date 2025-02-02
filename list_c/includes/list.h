/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:17:21 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:17:22 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <libft.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node	t_node;
typedef t_node			*t_node_ptr;
typedef struct s_list	t_list;
typedef t_list			*t_list_ptr;

struct					s_node
{
	char				*val;
	t_node				*prev;
	t_node				*next;
};

struct					s_list
{
	t_node				*head;
	t_node				*tail;
	int					size;
};

bool					empty_lt(t_list_ptr list);

t_list_ptr				init_lt(void);

void					push_back_lt(t_list_ptr list, char *const str);

void					push_back_move_lt(t_list_ptr list, char *const str);

void					move_back_lt(t_list_ptr *left, t_list_ptr right);

void					push_front_lt(t_list_ptr list, char *const str);

void					insert_node_lt(t_list_ptr list, char *str,
							t_node *node);

void					remove_if_lt(t_list_ptr list, char *val);

void					remove_index_node_lt(t_list_ptr list, int index);

t_node_ptr				remove_node_lt(t_list_ptr list, t_node *node);

void					remove_if_range_lt(t_list_ptr list, t_node *start,
							t_node *end, char *val);

void					pop_back_lt(t_list_ptr list);

void					pop_front_lt(t_list_ptr list);

void					clear_lt(t_list_ptr list);

char					*at_lt(t_list_ptr list, int index);

bool					diff_lt(char *word, char *to_cmp);

t_list_ptr				copy_lt(t_list_ptr other);

t_list_ptr				move_lt(t_list_ptr *other);

t_list_ptr				copy_range_lt(t_node *node, t_node *end);

int						value_counter_lt(t_list_ptr list, char *src);

t_node					*find_word_lt(t_node *node, char *word);
void					free_node(t_node **node);
t_node					*find_word_range_lt(t_node *curr, t_node *end,
							char *word);
t_node					*find_word_if_lt(t_node *node, bool (*p)(char *));
int						find_index_lt(t_list_ptr list, t_node *to_find);

// helpers.c
void					print_lt(t_list_ptr list);
t_node					*make_node(char *str);
t_node					*make_node_move(char *str);

// list_to_matrix
char					**from_head_to_matrix_lt(t_node_ptr head);
char					**list_to_matrix_lt(t_list_ptr list);

// size
int						size_from_head_lt(t_node_ptr head);
int						get_size(t_list_ptr list);

#endif // LIST_H
