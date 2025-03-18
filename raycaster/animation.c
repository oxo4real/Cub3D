/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:25:13 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/18 03:04:40 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static void	draw_animation_elements(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < 13)
	{
		if (anim->frames[i])
		{
			mlx_image_to_window(anim->mlx, anim->frames[i], (WIDTH / 2)
				- (anim->frames[i]->width / 2), HEIGHT
				- (int32_t)anim->frames[i]->height);
			anim->frames[i]->enabled = 0;
		}
		i++;
	}
	if (anim->idle)
	{
		mlx_image_to_window(anim->mlx, anim->idle, (WIDTH / 2)
			- anim->idle->width / 2, HEIGHT - (int32_t)anim->idle->height);
		anim->idle->enabled = 0;
	}
	if (anim->cross)
	{
		mlx_image_to_window(anim->mlx, anim->cross, (WIDTH / 2)
			- anim->cross->width / 2, (HEIGHT / 2) - (anim->cross->height / 2));
	}
}

bool	init_animation(mlx_t *mlx, t_anim *anim)
{
	anim->is_idle = 1;
	anim->mlx = mlx;
	if (load_animation_textures(anim))
		return (raise(MLX), 1);
	if (load_animation_images(anim))
		return (raise(MLX), 1);
	draw_animation_elements(anim);
	return (0);
}

void	animation_handler(void *param)
{
	t_anim	*anim;

	anim = param;
	if (!anim->is_idle)
	{
		if (anim->prev)
			anim->prev->enabled = 0;
		anim->prev = anim->frames[anim->cur_frame];
		anim->prev->enabled = 1;
		if (anim->cur_frame + 2 >= 13)
			anim->is_idle = 1;
		anim->cur_frame = (anim->cur_frame + 2) % 13;
	}
	if (anim->is_idle)
	{
		if (anim->prev)
			anim->prev->enabled = 0;
		anim->prev = anim->idle;
		anim->prev->enabled = 1;
	}
	if ((mlx_is_mouse_down(anim->mlx, MLX_MOUSE_BUTTON_LEFT)
			|| mlx_is_key_down(anim->mlx, MLX_KEY_SPACE)) && anim->is_idle)
		anim->is_idle = 0;
}
