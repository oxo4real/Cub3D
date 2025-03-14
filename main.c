/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:14:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/14 05:38:12 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "parser.h"
#include "raycaster.h"
#include "utils.h"
#include <math.h>
#include <sys/time.h>

void	leaks(void)
{
	system("leaks -q cub3d");
}

int	map_the_map(t_info *inf, int x, int y)
{
	char		**map;
	int			map_X;
	int			map_Y;
	t_player	p;

	p = inf->player;
	map_X = floor(p.x - inf->factor / 2 + (double)x / 300 * inf->factor);
	map_Y = floor(p.y - inf->factor / 2 + (double)y / 300 * inf->factor);
	// printf("X: %d, Y: %d\n", map_X, map_Y);
	map = inf->map;
	if (map_Y >= 0 && map_X >= 0 && map_Y < inf->height
		&& map_X < (int)ft_strlen(map[map_Y]))
	{
		if (map[map_Y][map_X] == '0')
			return (0X6fd4edFF);
		else if (map[map_Y][map_X] == '1')
			return (0X030061FF);
	}
	return (0X777777FF);
}

void	minimap(t_info *inf, mlx_t *mlx)
{
	static mlx_image_t	*img = NULL;
	int					i;
	int					j;
	const int			SCALE = 30;

	(void)inf;
	mlx_delete_image(mlx, img);
	img = mlx_new_image(mlx, 10 * SCALE, 10 * SCALE);
	i = 0;
	while (i < 10 * SCALE)
	{
		j = 0;
		while (j < 10 * SCALE)
		{
			mlx_put_pixel(img, j, i, map_the_map(inf, j, i));
			j++;
		}
		i++;
	}
	draw_square(img, 150 - 4, 150 - 4, 8, 0XFF00FF);
	for (int i = 0; i < 15; i++)
		mlx_put_pixel(img, 150 + (i * cos(inf->player.dir)), 150 + (i
				* sin(inf->player.dir)), 0XFF00FF);
	mlx_image_to_window(mlx, img, 0, 0);
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
		if (i > 505)
		{
			inf->player.dir += 0.08;
			if (inf->player.dir > 2 * PI)
				inf->player.dir -= 2 * PI;
		}
		else if (i < 495)
		{
			inf->player.dir -= 0.08;
			if (inf->player.dir < 0)
				inf->player.dir += 2 * PI;
		}
		prev_i = i;
	}
	mlx_set_mouse_pos(inf->mlx, 500, 500);
}

void	key_event(void *param)
{
	t_info	*inf;

	inf = param;
	if (mlx_is_key_down(inf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(inf->mlx);
	if (mlx_is_key_down(inf->mlx, MLX_KEY_D))
	{
		inf->player.x -= 0.1 * sin(inf->player.dir);
		inf->player.y += 0.1 * cos(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_A))
	{
		inf->player.x += 0.1 * sin(inf->player.dir);
		inf->player.y -= 0.1 * cos(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_W))
	{
		inf->player.x += 0.1 * cos(inf->player.dir);
		inf->player.y += 0.1 * sin(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_S))
	{
		inf->player.x -= 0.1 * cos(inf->player.dir);
		inf->player.y -= 0.1 * sin(inf->player.dir);
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_RIGHT))
	{
		inf->player.dir += 0.04;
		if (inf->player.dir > 2 * PI)
			inf->player.dir -= 2 * PI;
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_LEFT))
	{
		inf->player.dir -= 0.04;
		if (inf->player.dir < 0)
			inf->player.dir += 2 * PI;
	}
	if (mlx_is_key_down(inf->mlx, MLX_KEY_KP_ADD) && inf->factor > 2)
		inf->factor *= 0.95;
	if (mlx_is_key_down(inf->mlx, MLX_KEY_KP_SUBTRACT) && inf->factor < 40)
		inf->factor /= 0.95;
}

void	init_cub(t_info *inf, mlx_t *mlx)
{
	extract_info(inf);
	inf->mlx = mlx;
	inf->factor = 10;
	mlx_set_cursor_mode(mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(mlx, event, inf);
	mlx_loop_hook(mlx, mouse_event, inf);
	mlx_loop_hook(mlx, key_event, inf);
}

int	main(int ac, char *av[])
{
	t_info		inf;
	mlx_image_t	*img[2] = {NULL};
	mlx_t		*mlx;

	// atexit(leaks);
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
	img[0] = mlx_new_image(mlx, 1920, 1920);
	draw_square(img[0], 0, 0, 1920, 0XFFFFFF);
	mlx_image_to_window(mlx, img[0], 0, 0);
	init_cub(&inf, mlx);
	mlx_loop(mlx);
	free_info(&inf);
	mlx_terminate(mlx);
	return (0);
}
