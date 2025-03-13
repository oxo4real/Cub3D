/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:06:37 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/13 00:06:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_info(t_info *inf)
{
	int	i;

	i = 0;
	while (i < UNDEFINED)
	{
		if (inf->data[i])
		{
			free(inf->data[i]);
			inf->data[i] = NULL;
		}
		i++;
	}
	if (inf->map)
	{
		freestrarr(&inf->map);
		inf->map = NULL;
	}
}
