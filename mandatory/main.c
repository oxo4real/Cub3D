/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:14:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 03:54:19 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "raycaster.h"

bool	init_cub(t_info *inf, mlx_t *mlx)
{
	extract_info(inf);
	inf->mlx = mlx;
	inf->factor = 1;
	inf->last_time = mlx_get_time();
	inf->frame = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!inf->frame)
		return (1);
	mlx_image_to_window(mlx, inf->frame, 0, 0);
	if (load_textures(inf))
		return (1);
	hook_events(mlx, inf);
	return (0);
}

int	main(int ac, char *av[])
{
	t_info	inf;
	mlx_t	*mlx;

	if (ac != 2)
	{
		printf("Usage: %s <map>.cub\n", av[0]);
		return (1);
	}
	if (parser(av[1], &inf))
		return (1);
	mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!mlx)
		return (free_info(&inf), 1);
	if (!init_cub(&inf, mlx))
		mlx_loop(mlx);
	free_info(&inf);
	mlx_terminate(mlx);
	return (0);
}
