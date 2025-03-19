/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:12:42 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 01:07:51 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static void	free_animation_helper(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (anim->t_fire[i])
			mlx_delete_texture(anim->t_fire[i]);
		if (anim->i_fire[i])
			mlx_delete_image(anim->mlx, anim->i_fire[i]);
		if (anim->t_aim_fire[i])
			mlx_delete_texture(anim->t_aim_fire[i]);
		if (anim->i_aim_fire[i])
			mlx_delete_image(anim->mlx, anim->i_aim_fire[i]);
		if (i < 4)
		{
			if (anim->t_aim[i])
				mlx_delete_texture(anim->t_aim[i]);
			if (anim->i_aim[i])
				mlx_delete_image(anim->mlx, anim->i_aim[i]);
		}
		i++;
	}
}

void	free_animation(t_anim *anim)
{
	free_animation_helper(anim);
	if (anim->t_idle)
		mlx_delete_texture(anim->t_idle);
	if (anim->idle)
		mlx_delete_image(anim->mlx, anim->idle);
	if (anim->t_cross)
		mlx_delete_texture(anim->t_cross);
	if (anim->cross)
		mlx_delete_image(anim->mlx, anim->cross);
}
