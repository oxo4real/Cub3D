/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:22:22 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/15 02:50:44 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parse_color(char *s, int *co)
{
	char	comma;
	int		i;

	comma = 0;
	i = 0;
	if (s[i] && s[i] == ',')
		return (raise(MALFORMED_FILE), 1);
	while (s[i])
	{
		if (s[i] != ',' && !(s[i] >= '0' && s[i] <= '9'))
			return (raise(MALFORMED_FILE), 1);
		if (s[i] == ',' && (s[i + 1] == ',' || !s[i + 1]))
			return (raise(MALFORMED_FILE), 1);
		if (s[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (raise(MALFORMED_FILE), 1);
	return (ato_color(s, co));
}

bool	parse_colors(t_info *inf)
{
	if (parse_color(inf->data[F], &inf->_f))
		return (1);
	if (parse_color(inf->data[C], &inf->_c))
		return (1);
	return (0);
}
