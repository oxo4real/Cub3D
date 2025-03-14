/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:34:56 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/14 05:35:03 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	extract_info(t_info *inf)
{
	int	max;
	int	j;
	int	i;

	i = 0;
	max = -1;
	while (inf->map[i])
	{
		j = 0;
		while (inf->map[i][j])
		{
			if (ft_isdirection(inf->map[i][j]))
			{
				inf->player = (t_player){j + 0.5, i + 0.5,
					get_direction(inf->map[i][j])};
				inf->map[i][j] = '0';
			}
			j++;
		}
		if (j > max)
			max = j;
		i++;
	}
	inf->max_width = max;
	inf->height = i;
}
