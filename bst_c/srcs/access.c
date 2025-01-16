/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:15:28 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:15:29 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bst.h>

t_value_type	get_bst(t_bst_ptr bst, const t_key_type key)
{
	t_treenode_ptr	to_find;

	to_find = _find_bst(bst->root, key);
	if (to_find == NULL)
		return (NULL);
	return (to_find->value);
}

t_value_type	get_bst_range(t_bst_ptr bst, const t_key_type begin,
		const t_key_type end)
{
	t_treenode_ptr	to_find;
	int				len;
	char			*key;

	len = ft_strlen_range(begin, end);
	key = ft_substr(begin, 0, len);
	to_find = _find_bst(bst->root, key);
	free(key);
	if (to_find == NULL)
		return (NULL);
	return (to_find->value);
}
