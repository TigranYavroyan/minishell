/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:41:26 by tigran            #+#    #+#             */
/*   Updated: 2024/09/21 12:57:37 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void clear_minishell(t_minishell_ptr* minishell)
{
	clear_lt((*minishell)->line);
	free((*minishell)->line);

	clear_bst(&(*minishell)->env);
	clear_bst(&(*minishell)->export);
	free(*minishell);
	*minishell = NULL;
}