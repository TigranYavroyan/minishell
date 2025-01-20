/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:13:31 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/20 17:26:19 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env(t_command_ptr command)
{
	if (!empty_lt(command->options))
		__err_msg_full__("env: ", "illegal option: ",
			command->options->head->val, INV_ARG);
	else if (!empty_lt(command->args))
		__err_msg_full__("env: ", command->args->head->val,
			": No such file or directory", CMD_NOT_FOUND);
	else
		traverse_bst(command->minishell->env, INORDER, NULL);
}
