/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:35:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/18 22:07:14 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H
#include "MLX42.h"
# include "types.h"
# include "utils.h"

void	draw_col(t_info *inf, int px);
double	hray_len(t_info *inf, double angle, t_ray *ray);
double	vray_len(t_info *inf, double angle, t_ray *ray);
void	raycast(t_info *inf);
void	minimap(t_info *inf);
bool	init_minimap(t_info *inf);
void	minimap_event(void *param);
void	mouse_event(void *param);
void	key_event(void *param);
void	hook_events(mlx_t *mlx, t_info *inf, t_anim *anim);
void	ft_move(double new_x, double new_y, t_info *inf);
bool	init_animation(mlx_t *mlx, t_anim *anim);
void	animation_handler(void *param);
bool	load_animation_textures(t_anim *anim);
bool	load_animation_images(t_anim *anim);
void	free_animation(t_anim *anim);
void	toogle_door(struct mlx_key_data key, void *param);
double	hray_len_door(t_info *inf, double angle, t_ray *ray);
double	vray_len_door(t_info *inf, double angle, t_ray *ray);

#endif
