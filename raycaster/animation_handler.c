/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:43:34 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 01:10:50 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static void	anim_handler_move(t_anim *anim)
{
	if (mlx_is_mouse_down(anim->mlx, MLX_MOUSE_BUTTON_LEFT)
		&& mlx_is_mouse_down(anim->mlx, MLX_MOUSE_BUTTON_RIGHT))
	{
		anim->stat = SHOOTING_AIM;
		anim->cross->enabled = 0;
	}
	else if ((mlx_is_mouse_down(anim->mlx, MLX_MOUSE_BUTTON_LEFT)
			|| mlx_is_key_down(anim->mlx, MLX_KEY_SPACE)) && anim->stat == IDLE)
		anim->stat = SHOOTING;
	else if (mlx_is_mouse_down(anim->mlx, MLX_MOUSE_BUTTON_RIGHT))
	{
		anim->stat = AIMING;
		anim->cross->enabled = 0;
	}
	else if (anim->stat == AIMING)
	{
		anim->stat = BACK_AIMING;
		anim->frame_aim = 3;
	}
}

static void	anim_shoot(t_anim *anim)
{
	anim->prev = anim->i_fire[anim->frame_fire];
	if (anim->frame_fire + 1 >= 6)
		anim->stat = IDLE;
	anim->frame_fire = (anim->frame_fire + 1) % 6;
	anim->cross->enabled = 1;
}

static void	anim_shoot_aim(t_anim *anim)
{
	anim->prev = anim->i_aim_fire[anim->frame_aim_fire];
	if (anim->frame_aim_fire + 1 >= 6)
		anim->stat = AIMING;
	anim->frame_aim_fire = (anim->frame_aim_fire + 1) % 6;
}

static void	anim_aim(t_anim *anim)
{
	anim->prev = anim->i_aim[anim->frame_aim];
	if (anim->stat == AIMING && anim->frame_aim + 1 < 4)
		anim->frame_aim = (anim->frame_aim + 1) % 4;
	else if (anim->stat == BACK_AIMING)
		anim->frame_aim -= 1;
	if (anim->frame_aim < 0)
	{
		anim->stat = IDLE;
		anim->frame_aim = 0;
	}
}

void	animation_handler(void *param)
{
	t_anim	*anim;

	anim = param;
	if (anim->prev)
		anim->prev->enabled = 0;
	if (anim->stat == SHOOTING)
		anim_shoot(anim);
	else if (anim->stat == SHOOTING_AIM)
		anim_shoot_aim(anim);
	else if (anim->stat == AIMING || anim->stat == BACK_AIMING)
		anim_aim(anim);
	else if (anim->stat == IDLE)
	{
		anim->prev = anim->idle;
		anim->cross->enabled = 1;
	}
	anim_handler_move(anim);
	anim->prev->enabled = 1;
}
