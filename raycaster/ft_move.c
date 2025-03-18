/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:31:18 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/18 17:10:54 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ft_move(double new_x, double new_y, t_info *inf)
{
	if (inf->map[(int)inf->player.y][(int)new_x] != '1')
		inf->player.x = new_x;
	if (inf->map[(int)new_y][(int)inf->player.x] != '1')
		inf->player.y = new_y;
}
