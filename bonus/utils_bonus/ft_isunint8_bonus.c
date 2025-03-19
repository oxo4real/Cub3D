/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isunint8_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:58:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

bool	ft_isunint8(char *s)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	while (s[i + len])
	{
		if (!ft_isdigit(s[i + len]))
			return (0);
		len++;
	}
	if (*(s + 1) == '0' && len < 1)
		len++;
	if (!*s || (*s == '+' && len < 1) || len > 3)
		return (0);
	if (len < 3)
		return (1);
	return (ft_strcmp(s + i, "255") <= 0);
}
