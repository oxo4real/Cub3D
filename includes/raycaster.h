/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:35:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 22:35:35 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H
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
void	hook_events(mlx_t *mlx, t_info *inf);
void	ft_move(double new_x, double new_y, t_info *inf);

#endif
