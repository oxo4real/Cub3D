/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:38:28 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 03:48:38 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "raycaster.h"

void	raycast_event(void *param)
{
	raycast(param);
}

void	hook_events(mlx_t *mlx, t_info *inf)
{
	mlx_loop_hook(mlx, key_event, inf);
	mlx_loop_hook(mlx, raycast_event, inf);
}
