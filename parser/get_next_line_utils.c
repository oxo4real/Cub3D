/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:51:36 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/12 16:54:00 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
