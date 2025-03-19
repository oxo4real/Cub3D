/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:20:49 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static bool	color_convert(char *s, u_int8_t rgb[3])
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s && j < 3)
	{
		if (s[i] == ',' || !s[i])
		{
			tmp = s[i];
			s[i] = 0;
			if (ft_isunint8(s))
				rgb[j++] = ft_atou(s);
			else
				return (raise(MALFORMED_FILE), 1);
			s[i] = 0 | tmp;
			s = &s[i + 1];
			i = 0;
		}
		else
			i++;
	}
	return (0);
}

bool	ato_color(char *s, int *co)
{
	u_int8_t	rgb[3];

	if (color_convert(s, rgb))
		return (1);
	*co = get_rgb(rgb[0], rgb[1], rgb[2]);
	return (0);
}
