/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 06:27:14 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 06:29:14 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	load_textures(t_info *inf)
{
	inf->t[NO] = mlx_load_png(inf->data[NO]);
	if (!inf->t[NO])
		return (1);
	inf->t[SO] = mlx_load_png(inf->data[SO]);
	if (!inf->t[SO])
		return (1);
	inf->t[WE] = mlx_load_png(inf->data[WE]);
	if (!inf->t[WE])
		return (1);
	inf->t[EA] = mlx_load_png(inf->data[EA]);
	if (!inf->t[EA])
		return (1);
	return (0);
}

void	unload_textures(t_info *inf)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (inf->t[i])
			mlx_delete_texture(inf->t[i]);
		i++;
	}
}
