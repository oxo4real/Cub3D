/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:51:36 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:08 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

int	check_for(char *buff, char c)
{
	int	i;

	i = 0;
	while (buff && buff[i])
	{
		if (buff[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
