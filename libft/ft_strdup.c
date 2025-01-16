/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:17:17 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:17:17 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dup;
	char	*tmp_dup;

	dup = (char *)wrapper_malloc(ft_strlen(src) + 1);
	tmp_dup = dup;
	while (src && *src)
	{
		*dup = *src;
		++dup;
		++src;
	}
	*dup = '\0';
	return (tmp_dup);
}
