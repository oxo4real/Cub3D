/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:04:23 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/16 21:40:20 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_type	match_type(char *s)
{
	if (!s || !*s)
		return (UNDEFINED);
	if (*s == 'N' && *(s + 1) == 'O' && is_space(*(s + 2)))
		return (NO);
	else if (*s == 'S' && *(s + 1) == 'O' && is_space(*(s + 2)))
		return (SO);
	else if (*s == 'W' && *(s + 1) == 'E' && is_space(*(s + 2)))
		return (WE);
	else if (*s == 'E' && *(s + 1) == 'A' && is_space(*(s + 2)))
		return (EA);
	else if (*s == 'F' && is_space(*(s + 1)))
		return (F);
	else if (*s == 'C' && is_space(*(s + 1)))
		return (C);
	return (UNDEFINED);
}

char	*match_type_str(t_type type)
{
	if (type == C)
		return ("C");
	if (type == EA)
		return ("EA");
	if (type == SO)
		return ("SO");
	if (type == F)
		return ("F");
	if (type == WE)
		return ("WE");
	if (type == NO)
		return ("NO");
	return ("UNDEFINED");
}
