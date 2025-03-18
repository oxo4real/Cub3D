/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hray_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:22:43 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/17 23:22:35 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include <limits.h>
#include <math.h>

static void	init_vars(t_ray *ray, t_info *inf, double angle);
static bool	ray_in_map(t_ray *ray, t_info *inf);
static bool	player_in_wall(t_info *inf);

double	hray_len(t_info *inf, double angle, t_ray *ray)
{
	int	i;

	init_vars(ray, inf, angle);
	if (player_in_wall(inf))
		return (sqrt(pow(inf->player.y - ray->ry, 2) + pow(inf->player.x
					- ray->rx, 2)));
	i = 0;
	while (i < DOF)
	{
		if (ray_in_map(ray, inf) && inf->map[(int)ray->ry][(int)ray->rx] == '1')
			return (sqrt(pow(inf->player.y - ray->ry, 2) + pow(inf->player.x
						- ray->rx, 2)));
		ray->ry += ray->yo;
		ray->rx += ray->xo;
		i++;
	}
	return (INT_MAX);
}

static void	init_vars(t_ray *ray, t_info *inf, double angle)
{
	if (angle >= M_PI)
	{
		ray->ry = floor(inf->player.y) - 0.000001;
		ray->rx = (inf->player.y - ray->ry) * (-1 / tan(angle)) + inf->player.x;
		ray->yo = -1;
		ray->xo = -ray->yo * (-1 / tan(angle));
	}
	else if (angle < M_PI)
	{
		ray->ry = ceil(inf->player.y);
		ray->rx = (inf->player.y - ray->ry) * (-1 / tan(angle)) + inf->player.x;
		ray->yo = 1;
		ray->xo = -ray->yo * (-1 / tan(angle));
	}
}

static bool	ray_in_map(t_ray *ray, t_info *inf)
{
	return (ray->ry < inf->height && ray->ry >= 0 && ray->rx >= 0
		&& ray->rx < (int)ft_strlen(inf->map[(int)ray->ry]));
}

static bool	player_in_wall(t_info *inf)
{
	return (inf->player.y < inf->height && inf->player.y >= 0
		&& inf->player.x >= 0
		&& inf->player.x < ft_strlen(inf->map[(int)inf->player.y])
		&& inf->map[(int)inf->player.y][(int)inf->player.x] == '1');
}
