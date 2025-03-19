/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 04:00:55 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 04:00:56 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_BONUS_H
# define RAYCASTER_BONUS_H
# include "MLX42.h"
# include "types_bonus.h"
# include "utils_bonus.h"

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
void	toggle_door(struct mlx_key_data key, void *param);
double	hray_len_door(t_info *inf, double angle, t_ray *ray);
double	vray_len_door(t_info *inf, double angle, t_ray *ray);

#endif
