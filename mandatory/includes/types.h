/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:38:44 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 03:51:44 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include <MLX42.h>

typedef enum e_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	UNDEFINED
}					t_type;

typedef struct s_ray
{
	double			yo;
	double			xo;
	double			ry;
	double			rx;
}					t_ray;

typedef struct s_draw_col_vars
{
	double			ray_len;
	double			angle;
	int				ceiling_end;
	double			vlen;
	double			hlen;
	t_ray			ray1;
	t_ray			ray2;
}					t_draw_col_vars;

typedef struct s_player
{
	double			x;
	double			y;
	double			dir;
}					t_player;

typedef struct s_info
{
	char			*data[6];
	mlx_texture_t	*t[4];
	char			**map;
	mlx_t			*mlx;
	mlx_image_t		*frame;
	double			factor;
	double			last_time;
	double			dt;
	t_player		player;
	int				max_width;
	int				height;
	int				_f;
	int				_c;
}					t_info;

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

typedef struct s_head
{
	t_list			*head;
	t_list			*last;
	int				size;
}					t_head;

#endif
