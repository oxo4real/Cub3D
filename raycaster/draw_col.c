/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:25:10 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/18 03:24:55 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static double		ft_map(int px, t_info *inf);
static unsigned int	gt_clr(t_ray *ray, t_info *inf, t_type dir,
						double factor_y);
static void			put_pixel(t_draw_col_vars vars, t_info *inf, int i, int px);

void	draw_col(t_info *inf, int px)
{
	t_draw_col_vars	vars;
	int				i;

	vars.angle = ft_map(px, inf);
	vars.vlen = vray_len(inf, vars.angle, &vars.ray1);
	vars.hlen = hray_len(inf, vars.angle, &vars.ray2);
	vars.ray_len = ft_min(vars.vlen, vars.hlen) * cos(inf->player.dir
			- vars.angle);
	vars.ceiling_end = (int)((HEIGHT / 2.0) - HEIGHT / vars.ray_len);
	i = 0;
	while (i < HEIGHT)
	{
		put_pixel(vars, inf, i, px);
		i++;
	}
}

static void	put_pixel(t_draw_col_vars vars, t_info *inf, int i, int px)
{
	double	factor_y;

	factor_y = (double)(i - vars.ceiling_end) / (HEIGHT - 2 * vars.ceiling_end);
	if (i < vars.ceiling_end)
		mlx_put_pixel(inf->frame, px, i, inf->_c);
	else if (i < HEIGHT - vars.ceiling_end)
	{
		if (vars.ray_len == vars.hlen * cos(inf->player.dir - vars.angle))
		{
			if (inf->player.dir > M_PI)
				mlx_put_pixel(inf->frame, px, i, gt_clr(&vars.ray2, inf, SO,
						factor_y));
			else
				mlx_put_pixel(inf->frame, px, i, gt_clr(&vars.ray2, inf, NO,
						factor_y));
		}
		else if (vars.angle <= 3 * M_PI_2 && vars.angle >= M_PI_2)
			mlx_put_pixel(inf->frame, px, i, gt_clr(&vars.ray1, inf, WE,
					factor_y));
		else
			mlx_put_pixel(inf->frame, px, i, gt_clr(&vars.ray1, inf, EA,
					factor_y));
	}
	else
		mlx_put_pixel(inf->frame, px, i, inf->_f);
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

static unsigned int	gt_clr(t_ray *ray, t_info *inf, t_type dir, double factor_y)
{
	double			factor_x;
	mlx_texture_t	*texture;
	unsigned int	x;
	unsigned int	y;
	unsigned char	*px;

	if (dir == SO)
		factor_x = (fmod(ray->rx, 1));
	else if (dir == NO)
		factor_x = 1 - (fmod(ray->rx, 1));
	else if (dir == WE)
		factor_x = 1 - (fmod(ray->ry, 1));
	else
		factor_x = (fmod(ray->ry, 1));
	texture = inf->t[dir];
	x = (unsigned int)(factor_x * texture->width) * texture->bytes_per_pixel;
	y = (unsigned int)(texture->height * factor_y) * texture->bytes_per_pixel;
	px = texture->pixels + y * texture->width + x;
	return (get_rgba(px[0], px[1], px[2], px[3]));
}
