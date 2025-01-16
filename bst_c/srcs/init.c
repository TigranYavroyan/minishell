/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:15:53 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:15:53 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

static t_treenode_ptr	_copy(t_treenode_ptr from);

t_bst_ptr	init_bst(void)
{
	t_bst_ptr	tree;

	tree = (t_bst_ptr)wrapper_malloc(sizeof(t_bst));
	tree->root = NULL;
	tree->size = 0;
	return (tree);
}

t_bst_ptr	copy_bst(const t_bst_ptr bst)
{
	t_bst_ptr	tree;

	tree = init_bst();
	tree->root = _copy(bst->root);
	return (tree);
}

static t_treenode_ptr	_copy(t_treenode_ptr from)
{
	t_treenode_ptr	root;

	if (!from)
		return (NULL);
	root = _make_node(from->key, from->value, NULL, NULL);
	root->left = _copy(from->left);
	root->right = _copy(from->right);
	return (root);
}
