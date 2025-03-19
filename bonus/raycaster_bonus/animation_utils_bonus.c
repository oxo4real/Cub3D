/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:25:52 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:32 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_bonus.h"

static bool	load_anim_text_helper(t_anim *anim)
{
	char	buff[50];
	int		i;

	i = 1;
	while (i <= 6)
	{
		snprintf(buff, sizeof(buff), "./textures/FIRE/hk53_fire.%d.png", i);
		anim->t_fire[i - 1] = mlx_load_png(buff);
		if (!anim->t_fire[i - 1])
			return (1);
		snprintf(buff, sizeof(buff), "./textures/AIM/hk53_aimfire.%d.png", i);
		anim->t_aim_fire[i - 1] = mlx_load_png(buff);
		if (!anim->t_aim_fire[i - 1])
			return (1);
		if (i <= 4)
		{
			snprintf(buff, sizeof(buff), "./textures/AIM/hk53_aim.%d.png", i);
			anim->t_aim[i - 1] = mlx_load_png(buff);
			if (!anim->t_aim[i - 1])
				return (1);
		}
		i++;
	}
	return (0);
}

bool	load_animation_textures(t_anim *anim)
{
	if (load_anim_text_helper(anim))
		return (1);
	anim->t_idle = mlx_load_png("./textures/hk53_idle.1.png");
	if (!anim->t_idle)
		return (1);
	anim->t_cross = mlx_load_png("./textures/crosshair.png");
	if (!anim->t_cross)
		return (1);
	return (0);
}

static bool	load_animation_images_(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (anim->t_fire[i])
		{
			anim->i_fire[i] = mlx_texture_to_image(anim->mlx, anim->t_fire[i]);
			if (!anim->i_fire[i])
				return (1);
			anim->i_aim_fire[i] = mlx_texture_to_image(anim->mlx,
					anim->t_aim_fire[i]);
			if (!anim->i_aim_fire[i])
				return (1);
		}
		if (i < 4 && anim->t_aim[i])
		{
			anim->i_aim[i] = mlx_texture_to_image(anim->mlx, anim->t_aim[i]);
			if (!anim->i_aim[i])
				return (1);
		}
		i++;
	}
	return (0);
}

bool	load_animation_images(t_anim *anim)
{
	if (load_animation_images_(anim))
		return (1);
	anim->idle = mlx_texture_to_image(anim->mlx, anim->t_idle);
	if (!anim->idle)
		return (1);
	anim->cross = mlx_texture_to_image(anim->mlx, anim->t_cross);
	if (!anim->cross)
		return (1);
	return (0);
}
