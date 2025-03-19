/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:35:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 03:51:31 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H
# include "MLX42.h"
# include "types.h"
# include "utils.h"

void	draw_col(t_info *inf, int px);
double	hray_len(t_info *inf, double angle, t_ray *ray);
double	vray_len(t_info *inf, double angle, t_ray *ray);
void	raycast(t_info *inf);
void	key_event(void *param);
void	hook_events(mlx_t *mlx, t_info *inf);
void	ft_move(double new_x, double new_y, t_info *inf);

#endif
