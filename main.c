/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:14:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/18 03:32:54 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "raycaster.h"

void	leaks(void)
{
	system("leaks -q cub3D");
}

bool	init_cub(t_info *inf, mlx_t *mlx, t_anim *anim)
{
	extract_info(inf);
	ft_bzero(anim, sizeof(t_anim));
	inf->mlx = mlx;
	inf->factor = 1;
	inf->last_time = mlx_get_time();
	mlx_set_cursor_mode(mlx, MLX_MOUSE_HIDDEN);
	inf->frame = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!inf->frame)
		return (1);
	mlx_image_to_window(mlx, inf->frame, 0, 0);
	if (init_minimap(inf) || load_textures(inf) || init_animation(mlx, anim))
		return (1);
	hook_events(mlx, inf, anim);
	return (0);
}

int	main(int ac, char *av[])
{
	t_info	inf;
	mlx_t	*mlx;
	t_anim	anim;

	atexit(leaks);
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
	if (!init_cub(&inf, mlx, &anim))
		mlx_loop(mlx);
	free_info(&inf);
	free_animation(&anim);
	mlx_terminate(mlx);
	return (0);
}
