/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:12:44 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:12:44 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_dir_util(char *name)
{
	if (!name || !*name || !(name[0] == '.' || name[0] == '/'))
		return (false);
	return (true);
}

bool	is_dir(char *name, struct stat *info, int status)
{
	if (_equal(name, "."))
	{
		__err_msg_prmt__(".", ": filename argument required", INV_OPTION);
		return (true);
	}
	if (status == -1)
	{
		if (_equal(name + ft_strlen(name) - 1, "/"))
			__err_msg_prmt__(name, ": Not a directory", DIR_ERROR);
		else
			__err_msg_prmt__(name, ": No such file or directory",
				CMD_NOT_FOUND);
		return (true);
	}
	else if (S_ISDIR((*info).st_mode))
	{
		__err_msg_prmt__(name, ": is a directory", DIR_ERROR);
		return (true);
	}
	return (false);
}

bool	is_num_str(const char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			return (false);
		}
		++i;
	}
	return (true);
}

bool	is_quote(char ch)
{
	return (ch == '\'' || ch == '\"');
}

bool	is_mergeable_util(const char *str)
{
	return (!(_equal(str, ">") || _equal(str, "<") || _equal(str, "<<")
			|| _equal(str, ">>") || _equal(str, " ") || _equal(str, "|")
			|| _equal(str, "&&") || _equal(str, "||") || _equal(str, "&")));
}
