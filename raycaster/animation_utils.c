/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:25:52 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/18 02:59:33 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static bool	load_animation_helper(t_anim *anim)
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
	anim->t_cross = mlx_load_png("./textures/crosshair.png");
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
