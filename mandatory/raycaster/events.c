/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:48:58 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 03:35:21 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	move_event(t_info *inf)
{
	if (mlx_is_key_down(inf->mlx, MLX_KEY_D))
		ft_move(inf->player.x - 3 * inf->dt * sin(inf->player.dir),
			inf->player.y + 3 * inf->dt * cos(inf->player.dir), inf);
	if (mlx_is_key_down(inf->mlx, MLX_KEY_A))
		ft_move(inf->player.x + 3 * inf->dt * sin(inf->player.dir),
			inf->player.y - 3 * inf->dt * cos(inf->player.dir), inf);
	if (mlx_is_key_down(inf->mlx, MLX_KEY_W))
		ft_move(inf->player.x + 3 * inf->dt * cos(inf->player.dir),
			inf->player.y + 3 * inf->dt * sin(inf->player.dir), inf);
	if (mlx_is_key_down(inf->mlx, MLX_KEY_S))
		ft_move(inf->player.x - 3 * inf->dt * cos(inf->player.dir),
			inf->player.y - 3 * inf->dt * sin(inf->player.dir), inf);
}

void	key_event(void *param)
{
	t_info	*inf;

	inf = param;
	inf->dt = mlx_get_time() - inf->last_time;
	if (mlx_is_key_down(inf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(inf->mlx);
	move_event(inf);
	if (mlx_is_key_down(inf->mlx, MLX_KEY_RIGHT))
	{
		inf->player.dir += 2 * inf->dt;
		if (inf->player.dir > 2 * M_PI)
			inf->player.dir -= 2 * M_PI;
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_LEFT))
	{
		inf->player.dir -= 2 * inf->dt;
		if (inf->player.dir < 0)
			inf->player.dir += 2 * M_PI;
	}
	inf->last_time = mlx_get_time();
}
