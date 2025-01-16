/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ends_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:14:02 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 15:14:02 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_str_ends_with(char *haystack, char *needle)
{
	return (!ft_strncmp(haystack + ft_strlen(haystack) - ft_strlen(needle),
			needle, ft_strlen(needle)));
}
