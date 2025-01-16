/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:14 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:20:15 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	_count(char *input, char *delim)
{
	int	res;

	res = 0;
	while (input[res] != '\0' && !ft_strchr(delim, input[res]))
		++res;
	if (res == 0)
		return (1);
	return (res);
}

static void	ft_split_delim(t_list_ptr line, char *delim, char *input)
{
	int	i;
	int	len;

	i = 0;
	while (input[i] != '\0')
	{
		len = _count(input + i, delim);
		push_back_move_lt(line, ft_substr(input + i, 0, len));
		i += len;
	}
}

void	tokenize(t_minishell_ptr minishell, char *delim, char *input)
{
	ft_split_delim(minishell->line, delim, input);
}
