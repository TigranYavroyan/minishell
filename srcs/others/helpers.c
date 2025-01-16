/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:59 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:11:59 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	remove_2d_str(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i] != NULL)
		free(str[i]);
	free(str);
}

void	auto_free(char **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	ft_open(char *path, int flags, int permisson)
{
	int	fd;

	fd = open(path, flags, permisson);
	if (fd < 0)
	{
		if (errno == EACCES)
			__err_msg_prmt__(path, ": Permission denied", INV_ARG);
		else if (errno == ENOENT)
			__err_msg_prmt__(path, ": No such file or directory", INV_ARG);
		else if (errno == EISDIR)
			__err_msg_prmt__(path, ": is a directory", INV_ARG);
		return (-1);
	}
	return (fd);
}
