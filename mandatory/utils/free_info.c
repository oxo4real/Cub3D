/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:06:37 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 03:43:23 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
	if (inf->frame)
		mlx_delete_image(inf->mlx, inf->frame);
	unload_textures(inf);
}
