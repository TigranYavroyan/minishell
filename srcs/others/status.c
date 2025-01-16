/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:19:59 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:20:01 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		g_status;

void	set_status_unsigned(int status)
{
	g_status = (const unsigned char)status;
}

void	set_status_signed(int status)
{
	g_status = (const char)status;
}

void	set_status_int(int status)
{
	g_status = status;
}

int	get_status(void)
{
	return (g_status);
}
