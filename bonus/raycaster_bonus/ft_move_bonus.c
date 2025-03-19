/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:31:18 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/19 02:35:32 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_bonus.h"

void	ft_move(double new_x, double new_y, t_info *inf)
{
	if (inf->map[(int)inf->player.y][(int)new_x] != '1'
		&& inf->map[(int)inf->player.y][(int)new_x] != 'C')
		inf->player.x = new_x;
	if (inf->map[(int)new_y][(int)inf->player.x] != '1'
		&& inf->map[(int)new_y][(int)inf->player.x] != 'C')
		inf->player.y = new_y;
}
