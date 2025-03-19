/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimmed_len_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:17:20 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

size_t	ft_trimmed_len(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s && s[i])
	{
		if (is_space(s[i]))
			j++;
		else
			j = 0;
		i++;
	}
	return (i - j);
}
