/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:38:44 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 21:14:17 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "MLX42.h"

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

typedef struct s_player
{
	double			x;
	double			y;
	double			dir;
}					t_player;

typedef struct s_anim
{
	mlx_texture_t	*t[13];
	mlx_image_t		*frames[13];
	mlx_image_t		*prev;
	mlx_texture_t	*t_idle;
	mlx_image_t		*idle;
	mlx_texture_t	*t_cross;
	mlx_image_t		*cross;
	mlx_t			*mlx;
	double			last_time;
	int				cur_frame;
	bool			is_idle;
}					t_anim;

typedef struct s_info
{
	char			*data[6];
	mlx_texture_t	*t[4];
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
