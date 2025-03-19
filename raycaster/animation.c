/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:25:13 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 01:08:31 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static void	draw_n_hide(t_anim *anim, mlx_image_t *img)
{
	int32_t	x;
	int32_t	y;

	x = WIDTH / 2 - img->width / 2;
	y = HEIGHT - (int32_t)img->height;
	mlx_image_to_window(anim->mlx, img, x, y);
	img->enabled = 0;
}

static void	draw_animation_elements(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (anim->i_fire[i])
			draw_n_hide(anim, anim->i_fire[i]);
		if (anim->i_aim_fire[i])
			draw_n_hide(anim, anim->i_aim_fire[i]);
		if (i < 4 && anim->i_aim[i])
			draw_n_hide(anim, anim->i_aim[i]);
		i++;
	}
	if (anim->idle)
		draw_n_hide(anim, anim->idle);
	if (anim->cross)
		mlx_image_to_window(anim->mlx, anim->cross, (WIDTH / 2)
			- anim->cross->width / 2, (HEIGHT / 2) - (anim->cross->height / 2));
}

bool	init_animation(mlx_t *mlx, t_anim *anim)
{
	anim->stat = IDLE;
	anim->mlx = mlx;
	if (load_animation_textures(anim))
		return (raise(MLX), 1);
	if (load_animation_images(anim))
		return (raise(MLX), 1);
	draw_animation_elements(anim);
	return (0);
}
