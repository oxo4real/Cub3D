/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:04:23 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/13 00:04:41 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_type	match_type(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (!s || !*s)
		return (UNDEFINED);
	if (*s == 'N' && *(s + 1) == 'O' && len == 2)
		return (NO);
	else if (*s == 'S' && *(s + 1) == 'O' && len == 2)
		return (SO);
	else if (*s == 'W' && *(s + 1) == 'E' && len == 2)
		return (WE);
	else if (*s == 'E' && *(s + 1) == 'A' && len == 2)
		return (EA);
	else if (*s == 'F' && len == 1)
		return (F);
	else if (*s == 'C' && len == 1)
		return (C);
	return (UNDEFINED);
}
