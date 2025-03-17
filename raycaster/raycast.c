/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:58:48 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/17 02:40:31 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "raycaster.h"
#include "utils.h"

void	raycast(t_info *inf)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		draw_col(inf, i);
		i++;
	}
}
