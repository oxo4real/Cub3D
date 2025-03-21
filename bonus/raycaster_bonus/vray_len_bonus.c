/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vray_len_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:36:33 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/19 02:35:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static void	init_vars(t_ray *ray, t_info *inf, double angle);
static bool	ray_in_map(t_ray *ray, t_info *inf);
static bool	player_in_wall(t_info *inf);

double	vray_len(t_info *inf, double angle, t_ray *ray)
{
	int	i;

	init_vars(ray, inf, angle);
	if (player_in_wall(inf))
		return (sqrt(pow(inf->player.y - ray->ry, 2) + pow(inf->player.x
					- ray->rx, 2)));
	i = 0;
	while (i < DOF)
	{
		if ((ray_in_map(ray, inf))
			&& (inf->map[(int)ray->ry][(int)ray->rx] == '1'
			|| inf->map[(int)ray->ry][(int)ray->rx] == 'C'))
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
	if (angle >= 3 * M_PI_2 || angle <= M_PI_2)
	{
		ray->rx = ceil(inf->player.x);
		ray->ry = (inf->player.x - ray->rx) * -tan(angle) + inf->player.y;
		ray->xo = 1;
		ray->yo = -ray->xo * -tan(angle);
	}
	else if (angle <= 3 * M_PI_2 && angle >= M_PI_2)
	{
		ray->rx = floor(inf->player.x) - 0.00001;
		ray->ry = (inf->player.x - ray->rx) * -tan(angle) + inf->player.y;
		ray->xo = -1;
		ray->yo = -ray->xo * -tan(angle);
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
