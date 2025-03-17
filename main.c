/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:14:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 21:21:52 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "parser.h"
#include "raycaster.h"
#include "types.h"
#include "utils.h"

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
	if (init_minimap(inf) || load_textures(inf))
		return (1);
	hook_events(mlx, inf);
	return (0);
}
bool	load_animation_helper(t_anim *anim)
{
	anim->t[5] = mlx_load_png("./textures/hk53_fire.5.png");
	if (!anim->t[5])
		return (1);
	anim->t[6] = mlx_load_png("./textures/hk53_fire.7.png");
	if (!anim->t[6])
		return (1);
	anim->t[7] = mlx_load_png("./textures/hk53_fire.8.png");
	if (!anim->t[7])
		return (1);
	anim->t[8] = mlx_load_png("./textures/hk53_fire.9.png");
	if (!anim->t[8])
		return (1);
	anim->t[9] = mlx_load_png("./textures/hk53_fire.10.png");
	if (!anim->t[9])
		return (1);
	anim->t[10] = mlx_load_png("./textures/hk53_fire.11.png");
	if (!anim->t[10])
		return (1);
	anim->t[11] = mlx_load_png("./textures/hk53_fire.12.png");
	if (!anim->t[11])
		return (1);
	anim->t[12] = mlx_load_png("./textures/hk53_fire.13.png");
	if (!anim->t[12])
		return (1);
	return (0);
}

bool	load_animation_textures(t_anim *anim)
{
	anim->t[0] = mlx_load_png("./textures/hk53_fire.1.png");
	if (!anim->t[0])
		return (1);
	anim->t[1] = mlx_load_png("./textures/hk53_fire.2.png");
	if (!anim->t[1])
		return (1);
	anim->t[2] = mlx_load_png("./textures/hk53_fire.3.png");
	if (!anim->t[2])
		return (1);
	anim->t[3] = mlx_load_png("./textures/hk53_fire.4.png");
	if (!anim->t[3])
		return (1);
	anim->t[4] = mlx_load_png("./textures/hk53_fire.5.png");
	if (!anim->t[4])
		return (1);
	if (load_animation_helper(anim))
		return (1);
	anim->t_idle = mlx_load_png("./textures/hk53_idle.1.png");
	if (!anim->t_idle)
		return (1);
	anim->t_cross = mlx_load_png("./textures/KovaaK-Crosshair.png");
	if (!anim->t_cross)
		return (1);
	return (0);
}

bool	load_animation_images(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < 13)
	{
		if (anim->t[i])
		{
			anim->frames[i] = mlx_texture_to_image(anim->mlx, anim->t[i]);
			if (!anim->frames[i])
				return (1);
		}
		i++;
	}
	anim->idle = mlx_texture_to_image(anim->mlx, anim->t_idle);
	if (!anim->idle)
		return (1);
	anim->cross = mlx_texture_to_image(anim->mlx, anim->t_cross);
	if (!anim->cross)
		return (1);
	return (0);
}

void	free_animation(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < 13)
	{
		if (anim->t[i])
			mlx_delete_texture(anim->t[i]);
		if (anim->frames[i])
			mlx_delete_image(anim->mlx, anim->frames[i]);
		i++;
	}
	if (anim->t_idle)
		mlx_delete_texture(anim->t_idle);
	if (anim->idle)
		mlx_delete_image(anim->mlx, anim->idle);
	if (anim->t_cross)
		mlx_delete_texture(anim->t_cross);
	if (anim->cross)
		mlx_delete_image(anim->mlx, anim->cross);
}

bool	init_animation(mlx_t *mlx, t_anim *anim)
{
	int	i;

	ft_bzero(anim, sizeof(t_anim));
	anim->is_idle = 1;
	anim->mlx = mlx;
	anim->last_time = mlx_get_time();
	if (load_animation_textures(anim))
		return (free_animation(anim), 1);
	if (load_animation_images(anim))
		return (free_animation(anim), 1);
	i = 0;
	while (i < 13)
	{
		if (anim->frames[i])
		{
			mlx_image_to_window(anim->mlx, anim->frames[i], (WIDTH / 2)
				- (anim->frames[i]->width / 2), HEIGHT
				- anim->frames[i]->height);
			anim->frames[i]->enabled = 0;
		}
		i++;
	}
	if (anim->idle)
	{
		mlx_image_to_window(anim->mlx, anim->idle, (WIDTH / 2)
			- anim->idle->width / 2, HEIGHT - anim->idle->height);
		anim->idle->enabled = 0;
	}
	if (anim->cross)
	{
		mlx_image_to_window(anim->mlx, anim->cross, (WIDTH / 2)
			- anim->cross->width / 2, (HEIGHT / 2) - (anim->cross->height / 2));
	}
	return (0);
}

void	animation_handle(void *param)
{
	t_anim	*anim;

	anim = param;
	if (mlx_get_time() - anim->last_time >= (1.0 / 250) && !anim->is_idle)
	{
		if (anim->prev)
			anim->prev->enabled = 0;
		anim->prev = anim->frames[anim->cur_frame];
		anim->prev->enabled = 1;
		if (anim->cur_frame + 1 >= 13)
			anim->is_idle = 1;
		anim->cur_frame = (anim->cur_frame + 1) % 13;
		anim->last_time = mlx_get_time();
	}
	if (anim->is_idle)
	{
		if (anim->prev)
			anim->prev->enabled = 0;
		anim->prev = anim->idle;
		anim->prev->enabled = 1;
	}
	if (mlx_is_mouse_down(anim->mlx, MLX_MOUSE_BUTTON_LEFT) && anim->is_idle)
		anim->is_idle = 0;
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
	mlx = mlx_init(1920, 1080, "Cub3D", false);
	if (!mlx)
		return (free_info(&inf), 1);
	if (!init_cub(&inf, mlx))
	{
		init_animation(mlx, &anim);
		mlx_loop_hook(mlx, animation_handle, &anim);
		mlx_loop(mlx);
	}
	free_info(&inf);
	free_animation(&anim);
	mlx_terminate(mlx);
	return (0);
}
