/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:14:33 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/12 23:21:12 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strtrim_end(char *s)
{
	size_t	len;
	size_t	i;
	char	*new;

	i = 0;
	len = ft_trimmed_len(s);
	if (len == 0)
		return (ft_strdup(""));
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}
