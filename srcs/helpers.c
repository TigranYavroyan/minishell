/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:43:10 by tigran            #+#    #+#             */
/*   Updated: 2024/09/23 20:28:31 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void remove_2d_str (char** str)
{
	int	i;

	i = -1;
	while (str && str[++i] != NULL)
		free(str[i]);
	free(str);
}

bool is_quote(char ch)
{
	return (ch == '\'' || ch == '\"');
}

void __exit__(const char* name, const char* err)