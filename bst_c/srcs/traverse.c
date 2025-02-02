/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:16:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:16:13 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

static void	traverse_pre(t_treenode_ptr root, t_visitor_bst fptr);
static void	traverse_in(t_treenode_ptr root, t_visitor_bst fptr);
static void	traverse_post(t_treenode_ptr root, t_visitor_bst fptr);
static void	print_for_traverse_bst(t_key_type key, t_value_type value);

void	traverse_bst(t_bst_ptr tree, t_travers_type_bst travers_type,
		t_visitor_bst fptr)
{
	if (fptr == NULL)
		fptr = print_for_traverse_bst;
	if (travers_type == PREORDER)
		traverse_pre(tree->root, fptr);
	else if (travers_type == INORDER)
		traverse_in(tree->root, fptr);
	else if (travers_type == POSTORDER)
		traverse_post(tree->root, fptr);
	else
		_err("Invalid travers_type for traverse");
}

static void	traverse_pre(t_treenode_ptr root, t_visitor_bst fptr)
{
	if (!root)
		return ;
	fptr(root->key, root->value);
	traverse_pre(root->left, fptr);
	traverse_pre(root->right, fptr);
}

static void	traverse_in(t_treenode_ptr root, t_visitor_bst fptr)
{
	if (!root)
		return ;
	traverse_in(root->left, fptr);
	fptr(root->key, root->value);
	traverse_in(root->right, fptr);
}

static void	traverse_post(t_treenode_ptr root, t_visitor_bst fptr)
{
	if (!root)
		return ;
	traverse_post(root->left, fptr);
	traverse_post(root->right, fptr);
	fptr(root->key, root->value);
}

static void	print_for_traverse_bst(t_key_type key, t_value_type value)
{
	printf("%s=%s\n", key, value);
}
