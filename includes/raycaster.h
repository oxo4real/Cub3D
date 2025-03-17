/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:35:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 03:49:33 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H
# include "MLX42.h"
# include "types.h"

void	draw_square(mlx_image_t *img, int x, int y, int size, uint32_t color);
void	draw_col(t_info *inf, int px);
double	hray_len(t_info *inf, double angle);
double	vray_len(t_info *inf, double angle);
void	raycast(t_info *inf);

#endif
