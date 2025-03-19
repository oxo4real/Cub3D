/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:46:51 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

char	*copy_to_str(char *str, char **strs, char *sep, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	j;

	i = 0;
	x = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[x] = strs[i][j++];
			x++;
		}
		j = 0;
		while (i != size - 1 && sep[j] != '\0')
		{
			str[x] = sep[j++];
			x++;
		}
		i++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strsjoin(char **strs, char *sep)
{
	size_t	i;
	size_t	size;
	size_t	sum;
	char	*str;

	sum = 0;
	size = ft_arr_len(strs);
	if (size != 0)
	{
		i = 0;
		while (i < size)
		{
			sum += ft_strlen(strs[i]);
			i++;
		}
		sum += ft_strlen(sep) * (i - 1);
	}
	str = malloc(sizeof(char) * (sum + 1));
	if (str == NULL)
		return (NULL);
	copy_to_str(str, strs, sep, size);
	return (str);
}
