/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:48:58 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 06:42:39 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	mouse_event(void *param)
{
	t_info		*inf;
	static int	prev_i = 0;
	int			i;
	int			j;

	inf = param;
	mlx_get_mouse_pos(inf->mlx, &i, &j);
	if (i != prev_i)
	{
		if (i > 501)
		{
			inf->player.dir += 0.025;
			if (inf->player.dir > 2 * M_PI)
				inf->player.dir -= 2 * M_PI;
		}
		else if (i < 499)
		{
			inf->player.dir -= 0.025;
			if (inf->player.dir < 0)
				inf->player.dir += 2 * M_PI;
		}
		prev_i = i;
	}
	mlx_set_mouse_pos(inf->mlx, 500, 500);
}

static void	n_in_map(void *param)
{
	t_info	*inf;
	double	x;
	double	y;

	inf = (t_info *)param;
	if (inf->n)
		mlx_delete_image(inf->mlx, inf->n);
	inf->n = NULL;
	x = 300.0 / 2 - 140 * cos(inf->player.dir);
	y = 300.0 / 2 - 140 * sin(-inf->player.dir);
	inf->n = mlx_put_string(inf->mlx, "N", (int)x + -5, (int)y + -9);
}

void	minimap_event(void *param)
{
	t_info	*inf;

	inf = param;
	raycast(inf);
	minimap(inf);
	n_in_map(inf);
	if (mlx_is_key_down(inf->mlx, MLX_KEY_KP_ADD) && inf->factor > 1)
		inf->factor *= 0.95;
	if (mlx_is_key_down(inf->mlx, MLX_KEY_KP_SUBTRACT) && inf->factor < 5)
		inf->factor /= 0.95;
}

void	move_event(t_info *inf)
{
	if (mlx_is_key_down(inf->mlx, MLX_KEY_D))
	{
		inf->player.x -= 3 * inf->dt * sin(inf->player.dir);
		inf->player.y += 3 * inf->dt * cos(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_A))
	{
		inf->player.x += 3 * inf->dt * sin(inf->player.dir);
		inf->player.y -= 3 * inf->dt * cos(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_W))
	{
		inf->player.x += 3 * inf->dt * cos(inf->player.dir);
		inf->player.y += 3 * inf->dt * sin(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_S))
	{
		inf->player.x -= 3 * inf->dt * cos(inf->player.dir);
		inf->player.y -= 3 * inf->dt * sin(inf->player.dir);
	}
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
