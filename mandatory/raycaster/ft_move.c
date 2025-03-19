/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:31:18 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/19 03:35:37 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	ft_move(double new_x, double new_y, t_info *inf)
{
	inf->player.x = new_x;
	inf->player.y = new_y;
}
