/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_deli_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:44:11 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/19 02:35:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

char	*ft_strjoin_deli(char const *s1, char const *s2, char const *sep)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*rendu;

	if (!s1 || !s2 || !sep)
		return (NULL);
	size = ft_trimmed_len(s1) + ft_trimmed_len(s2) + ft_strlen(sep) + 1;
	rendu = (char *)malloc(size);
	if (!rendu)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_trimmed_len(s1))
		rendu[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(sep))
		rendu[i++] = sep[j++];
	j = 0;
	while (j < ft_trimmed_len(s2))
		rendu[i++] = s2[j++];
	rendu[i] = 0;
	return (rendu);
}
