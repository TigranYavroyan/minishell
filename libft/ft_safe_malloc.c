/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:13:53 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:13:54 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*wrapper_malloc(int bytes)
{
	void	*res;

	res = malloc(bytes);
	if (!res)
		_err("Malloc error");
	return (res);
}
