/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:14:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 06:03:06 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "raycaster.h"

void	leaks(void)
{
	system("leaks -q cub3D");
}

bool	init_cub(t_info *inf, mlx_t *mlx)
{
	extract_info(inf);
	inf->mlx = mlx;
	inf->factor = 1;
	inf->last_time = mlx_get_time();
	mlx_set_cursor_mode(mlx, MLX_MOUSE_HIDDEN);
	inf->frame = mlx_new_image(mlx, 1920, 1920);
	if (!inf->frame)
		return (1);
	mlx_image_to_window(mlx, inf->frame, 0, 0);
	if (init_minimap(inf))
		return (1);
	hook_events(mlx, inf);
	return (0);
}

int	main(int ac, char *av[])
{
	t_info	inf;
	mlx_t	*mlx;

	atexit(leaks);
	if (ac != 2)
	{
		printf("Usage: %s <map>.cub\n", av[0]);
		return (1);
	}
	if (parser(av[1], &inf))
		return (1);
	mlx = mlx_init(1920, 1080, "Cub3D", false);
	if (!mlx)
		return (free_info(&inf), 1);
	init_cub(&inf, mlx);
	mlx_loop(mlx);
	free_info(&inf);
	mlx_terminate(mlx);
	return (0);
}
