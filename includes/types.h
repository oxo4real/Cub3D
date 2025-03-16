/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 05:38:44 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/16 17:42:07 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H
#include "MLX42.h"

typedef enum e_type { NO, SO, WE, EA, F, C, UNDEFINED } t_type;

typedef struct s_player {
  double x;
  double y;
  double dir;
} t_player;

typedef struct s_info {
  char *data[6];
  char **map;
  mlx_t *mlx;
  t_player player;
  int max_width;
  int height;
  double factor;
  int _f;
  int _c;
  double last_time;
} t_info;

typedef struct s_list {
  char *line;
  struct s_list *next;
} t_list;

typedef struct s_head {
  t_list *head;
  t_list *last;
  int size;
} t_head;

#endif
