/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:15:45 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:15:45 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

int	get_height_bst(t_bst_ptr tree)
{
	if (!tree)
		return (-1);
	return (__get_height_bst(tree->root));
}

int	__get_height_bst(t_treenode_ptr root)
{
	int	left;
	int	right;
	int	max;

	if (!root)
		return (-1);
	left = __get_height_bst(root->left);
	right = __get_height_bst(root->right);
	if (left > right)
		max = left + 1;
	else
		max = right + 1;
	return (max);
}
