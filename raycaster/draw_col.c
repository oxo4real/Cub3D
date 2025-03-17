/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:25:10 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/17 17:03:41 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "utils.h"

static double	ft_map(int px, t_info *inf);

void	draw_col(t_info *inf, int px)
{
	double	ray_len;
	double	angle;
	int		ceiling_end;
	int		i;
	double	vlen;
	double	hlen;

	angle = ft_map(px, inf);
	vlen = vray_len(inf, angle);
	hlen = hray_len(inf, angle);
	ray_len = ft_min(vlen, hlen) * cos(inf->player.dir - angle);
	ceiling_end = (int)((HEIGHT / 2.0) - HEIGHT / ray_len);
	i = 0;
	while (i < HEIGHT)
	{
		if (i < ceiling_end)
			mlx_put_pixel(inf->frame, px, i, inf->_c);
		else if (i < HEIGHT - ceiling_end)
		{
			if (ray_len == hlen * cos(inf->player.dir - angle))
				mlx_put_pixel(inf->frame, px, i, 0xFF0000FF);
			else
				mlx_put_pixel(inf->frame, px, i, 0xAA0000FF);
		}
		else
			mlx_put_pixel(inf->frame, px, i, inf->_f);
		i++;
	}
}

static double	ft_map(int px, t_info *inf)
{
	double	ratio;
	double	angle;

	ratio = (double)px / (double)WIDTH;
	angle = FOV * ratio + (inf->player.dir - (FOV / 2.0));
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}
