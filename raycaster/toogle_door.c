/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toogle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:20:20 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/18 23:39:22 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "raycaster.h"
#include <complex.h>

static bool	ray_in_map(t_ray *ray, t_info *inf);

void	toogle_door(struct mlx_key_data key_data, void *param)
{
	t_draw_col_vars	vars;
	t_info			*inf;

	if (key_data.key == MLX_KEY_E && key_data.action == MLX_PRESS)
	{
		inf = (t_info *)param;
		vars.angle = inf->player.dir;
		vars.vlen = vray_len_door(inf, vars.angle, &vars.ray1);
		vars.hlen = hray_len_door(inf, vars.angle, &vars.ray2);
		vars.ray_len = ft_min(vars.vlen, vars.hlen);
		if (vars.ray_len == vars.hlen)
		{
			if (ray_in_map(&vars.ray2, inf)
				&& inf->map[(int)vars.ray2.ry][(int)vars.ray2.rx] == 'C')
				inf->map[(int)vars.ray2.ry][(int)vars.ray2.rx] = 'O';
			else if (ray_in_map(&vars.ray2, inf)
					&& inf->map[(int)vars.ray2.ry][(int)vars.ray2.rx] == 'O')
					inf->map[(int)vars.ray2.ry][(int)vars.ray2.rx] = 'C';
		}
		else
		{
			if (ray_in_map(&vars.ray1, inf)
				&& inf->map[(int)vars.ray1.ry][(int)vars.ray1.rx] == 'C')
				inf->map[(int)vars.ray1.ry][(int)vars.ray1.rx] = 'O';
			else if (ray_in_map(&vars.ray1, inf)
					&& inf->map[(int)vars.ray1.ry][(int)vars.ray1.rx] == 'O')
					inf->map[(int)vars.ray1.ry][(int)vars.ray1.rx] = 'C';
		}
	}
}

static bool	ray_in_map(t_ray *ray, t_info *inf)
{
	return (ray->ry < inf->height && ray->ry >= 0 && ray->rx >= 0
		&& ray->rx < (int)ft_strlen(inf->map[(int)ray->ry]));
}
