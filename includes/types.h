/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:38:44 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 01:27:39 by aaghzal          ###   ########.fr       */
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

typedef enum e_stat
{
	IDLE,
	AIMING,
	BACK_AIMING,
	SHOOTING,
	SHOOTING_AIM,
}					t_stat;

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

typedef struct s_anim
{
	mlx_texture_t	*t_fire[6];
	mlx_image_t		*i_fire[6];
	mlx_texture_t	*t_aim_fire[6];
	mlx_image_t		*i_aim_fire[6];
	mlx_texture_t	*t_aim[4];
	mlx_image_t		*i_aim[4];
	mlx_image_t		*prev;
	mlx_texture_t	*t_idle;
	mlx_image_t		*idle;
	mlx_texture_t	*t_cross;
	mlx_image_t		*cross;
	mlx_t			*mlx;
	int				frame_fire;
	int				frame_aim_fire;
	int				frame_aim;
	t_stat			stat;
}					t_anim;

typedef struct s_info
{
	char			*data[6];
	mlx_texture_t	*t[4];
	mlx_texture_t	*door;
	char			**map;
	mlx_t			*mlx;
	mlx_image_t		*frame;
	mlx_image_t		*m;
	mlx_image_t		*n;
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
