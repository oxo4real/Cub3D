/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:14:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 03:41:58 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "parser.h"
#include "raycaster.h"
#include "utils.h"
#include <math.h>

void	leaks(void)
{
	system("leaks -q cub3D");
}

int	map_the_map(t_info *inf, int x, int y)
{
	char		**map;
	t_player	p;
	double		cos_a;
	double		sin_a;
	double		local_x;
	double		local_y;
	int			map_X;
	int			map_Y;

	map = inf->map;
	p = inf->player;
	double angle = p.dir + M_PI_2 + -0.01; // Use the same direction as movement
	cos_a = cos(-angle);
	sin_a = sin(-angle);
	// Convert pixel position to world coordinates relative to player
	local_x = ((x - 5 * 30) / (double)30) * inf->factor;
	local_y = ((y - 5 * 30) / (double)30) * inf->factor;
	// Apply rotation transformation
	map_X = (int)floor(p.x + local_x * cos_a + local_y * sin_a);
	map_Y = (int)floor(p.y - local_x * sin_a + local_y * cos_a);
	// Ensure within map bounds
	if (map_Y >= 0 && map_Y < inf->height && map_X >= 0 && map[map_Y]
		&& map_X < (int)ft_strlen(map[map_Y]))
	{
		if (map[map_Y][map_X] == '0')
			return (0X6fd4edFF); // Floor
		else if (map[map_Y][map_X] == '1')
			return (0X030061FF); // Wall
	}
	return (0X777777FF); // Default color for out-of-bounds
}

void	minimap(t_info *inf, mlx_t *mlx)
{
	static mlx_image_t	*img = NULL;
	int					i;
	int					j;
	const int			SCALE = 30;
	static bool			is_ = 0;

	(void)inf;
	// mlx_delete_image(mlx, img);
	if (!img)
		img = mlx_new_image(mlx, 10 * SCALE, 10 * SCALE);
	i = 0;
	while (i < 10 * SCALE)
	{
		j = 0;
		while (j < 10 * SCALE)
		{
			if ((j - 300 / 2) * (j - 300 / 2) + (i - 300 / 2) * (i - 300
					/ 2) <= 140 * 140)
			{
				mlx_put_pixel(img, j, i, map_the_map(inf, j, i));
			}
			else if ((j - 300 / 2) * (j - 300 / 2) + (i - 300 / 2) * (i - 300
					/ 2) <= 150 * 150)
			{
				mlx_put_pixel(img, j, i, 0X00FF);
			}
			j++;
		}
		i++;
	}
	draw_square(img, 150 - 4, 150 - 4, 8, 0XFF00FF);
	for (int i = 0; i < 15; i++)
		mlx_put_pixel(img, 150, 150 - i, 0XFF00FF);
	if (!is_)
		mlx_image_to_window(mlx, img, 0, 0);
	is_ = 1;
}

void	event(void *param)
{
	t_info			*inf;
	static double	prev_y = 0;
	static double	prev_x = 0;
	static double	prev_dir = 0;

	inf = param;
	minimap(inf, inf->mlx);
	if (inf->player.x != prev_x || inf->player.y != prev_y
		|| inf->player.dir != prev_dir)
	{
		prev_x = inf->player.x;
		prev_y = inf->player.y;
		prev_dir = inf->player.dir;
	}
	raycast(inf);
}

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
			inf->player.dir += 0.03;
			if (inf->player.dir > 2 * M_PI)
				inf->player.dir -= 2 * M_PI;
		}
		else if (i < 499)
		{
			inf->player.dir -= 0.03;
			if (inf->player.dir < 0)
				inf->player.dir += 2 * M_PI;
		}
		prev_i = i;
	}
	mlx_set_mouse_pos(inf->mlx, 500, 500);
}

void	key_event(void *param)
{
	t_info	*inf;
	double	dt;

	inf = param;
	dt = mlx_get_time() - inf->last_time;
	if (mlx_is_key_down(inf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(inf->mlx);
	if (mlx_is_key_down(inf->mlx, MLX_KEY_D))
	{
		inf->player.x -= 3 * dt * sin(inf->player.dir);
		inf->player.y += 3 * dt * cos(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_A))
	{
		inf->player.x += 3 * dt * sin(inf->player.dir);
		inf->player.y -= 3 * dt * cos(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_W))
	{
		inf->player.x += 3 * dt * cos(inf->player.dir);
		inf->player.y += 3 * dt * sin(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_S))
	{
		inf->player.x -= 3 * dt * cos(inf->player.dir);
		inf->player.y -= 3 * dt * sin(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_RIGHT))
	{
		inf->player.dir += 2 * dt;
		if (inf->player.dir > 2 * M_PI)
			inf->player.dir -= 2 * M_PI;
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_LEFT))
	{
		inf->player.dir -= 2 * dt;
		if (inf->player.dir < 0)
			inf->player.dir += 2 * M_PI;
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_KP_ADD) && inf->factor > 1)
		inf->factor *= 0.95;
	if (mlx_is_key_down(inf->mlx, MLX_KEY_KP_SUBTRACT) && inf->factor < 5)
		inf->factor /= 0.95;
	inf->last_time = mlx_get_time();
}

void	init_cub(t_info *inf, mlx_t *mlx)
{
	extract_info(inf);
	inf->mlx = mlx;
	inf->factor = 1;
	inf->last_time = mlx_get_time();
	mlx_set_cursor_mode(mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(mlx, event, inf);
	mlx_loop_hook(mlx, mouse_event, inf);
	mlx_loop_hook(mlx, key_event, inf);
}

int	main(int ac, char *av[])
{
	t_info		inf;
	mlx_t		*mlx;

	atexit(leaks);
	(void)av;
	if (ac != 2)
	{
		printf("Usage: %s <map>.cub\n", av[0]);
		return (1);
	}
	if (parser(av[1], &inf))
		return (1);
	mlx = mlx_init(1920, 1080, "Cub3d", false);
	if (!mlx)
		return (1);
	inf.frame = mlx_new_image(mlx, 1920, 1920);
	draw_square(inf.frame, 0, 0, 1920, 0XFFFFFF);
	mlx_image_to_window(mlx, inf.frame, 0, 0);
	init_cub(&inf, mlx);
	mlx_loop(mlx);
	free_info(&inf);
	mlx_terminate(mlx);
	return (0);
}
