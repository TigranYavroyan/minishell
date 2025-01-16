/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:12:53 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:12:53 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_builtin(const char *val)
{
	if (_equal(val, "echo"))
		return (true);
	if (_equal(val, "cd"))
		return (true);
	if (_equal(val, "pwd"))
		return (true);
	if (_equal(val, "export"))
		return (true);
	if (_equal(val, "unset"))
		return (true);
	if (_equal(val, "env"))
		return (true);
	if (_equal(val, "exit"))
		return (true);
	return (false);
}
