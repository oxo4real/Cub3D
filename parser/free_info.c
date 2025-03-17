/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:06:37 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 05:46:12 by mhayyoun         ###   ########.fr       */
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
	mlx_delete_image(inf->mlx, inf->frame);
	mlx_delete_image(inf->mlx, inf->m);
	mlx_delete_image(inf->mlx, inf->n);
}
