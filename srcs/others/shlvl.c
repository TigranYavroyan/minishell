/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:00:11 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/20 21:15:59 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	level_check(t_value_type value)
{
	int	level;

	level = ft_atoi(value);
	if (level < 0)
		level = 0;
	else if (level >= 0 && level <= 999)
		++level;
	else
		level = 1;
	return (level);
}

static void	__shlvl_if_body(t_treenode_ptr found, t_treenode_ptr found2)
{
	int	level;

	level = level_check(found->value);
	if (level == 1000)
	{
		found->value = ft_strdup("");
		found2->value = ft_strdup("");
	}
	else
	{
		found->value = ft_itoa(level);
		found2->value = ft_itoa(level);
	}
	free(found->value);
	free(found2->value);
}

void	shlvl_process(t_minishell_ptr minishell)
{
	t_treenode_ptr	found;
	t_treenode_ptr	found2;

	found = _find_bst(minishell->env->root, "SHLVL");
	found2 = _find_bst(minishell->export->root, "SHLVL");
	if (found && found2)
		__shlvl_if_body(found, found2);
	else
	{
		insert_bst(minishell->export, "SHLVL", "1");
		insert_bst(minishell->env, "SHLVL", "1");
	}
}
