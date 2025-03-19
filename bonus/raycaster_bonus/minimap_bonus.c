/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:05:07 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:32 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_bonus.h"

static void	draw_player(mlx_image_t *img, uint32_t color)
{
	u_int32_t	i;
	u_int32_t	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			mlx_put_pixel(img, 150 - 4 + i, 150 - 4 + j, color);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 15)
	{
		mlx_put_pixel(img, 150, 150 - i, color);
		i++;
	}
}

static void	calc_point(t_info *inf, int *x, int *y, t_player *p)
{
	double	local_y;
	double	local_x;
	double	angle;

	angle = p->dir + M_PI_2 + -0.009;
	local_y = ((*y - 5 * 30) / (double)30) * inf->factor;
	local_x = ((*x - 5 * 30) / (double)30) * inf->factor;
	*x = (int)floor(p->x + local_x * cos(-angle) + local_y * sin(-angle));
	*y = (int)floor(p->y - local_x * sin(-angle) + local_y * cos(-angle));
}

static uint32_t	map_the_map(t_info *inf, int x, int y)
{
	char	**map;

	map = inf->map;
	calc_point(inf, &x, &y, &inf->player);
	if (y >= 0 && y < inf->height && x >= 0 && map[y]
		&& x < (int)ft_strlen(map[y]))
	{
		if (map[y][x] == '0')
			return (0X6fd4edFF);
		else if (map[y][x] == '1')
			return (0X030061FF);
		else if (map[y][x] == 'C' || map[y][x] == 'O')
			return (0XAA0000FF);
	}
	return (0X777777FF);
}

void	minimap(t_info *inf)
{
	u_int32_t	i;
	u_int32_t	j;
	const int	scale = 30;

	i = 0;
	while (i < 10 * scale)
	{
		j = 0;
		while (j < 10 * scale)
		{
			if ((j - 300 / 2) * (j - 300 / 2) + (i - 300 / 2) * (i - 300
					/ 2) <= 130 * 130)
				mlx_put_pixel(inf->m, j, i, map_the_map(inf, j, i));
			else if ((j - 300 / 2) * (j - 300 / 2) + (i - 300 / 2) * (i - 300
					/ 2) <= 150 * 150)
				mlx_put_pixel(inf->m, j, i, 0X00FF);
			j++;
		}
		i++;
	}
	draw_player(inf->m, 0XFF00FF);
}

bool	init_minimap(t_info *inf)
{
	const int	scale = 30;

	inf->m = mlx_new_image(inf->mlx, 10 * scale, 10 * scale);
	if (!inf->m)
		return (1);
	mlx_image_to_window(inf->mlx, inf->m, 0, 0);
	return (0);
}
