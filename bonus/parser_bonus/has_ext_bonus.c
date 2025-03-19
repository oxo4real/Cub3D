/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_ext_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:35:10 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:08 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

bool	has_ext(char *filename, char *ext)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(filename);
	len2 = ft_strlen(ext);
	if (len1 < len2)
		return (0);
	return (ft_strcmp(&filename[len1 - len2], ext) == 0);
}
