/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:38:28 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:15:05 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "raycaster.h"

void	hook_events(mlx_t *mlx, t_info *inf, t_anim *anim)
{
	mlx_loop_hook(mlx, minimap_event, inf);
	mlx_loop_hook(mlx, mouse_event, inf);
	mlx_loop_hook(mlx, key_event, inf);
	mlx_loop_hook(mlx, animation_handler, anim);
	mlx_key_hook(mlx, toggle_door, inf);
}
