/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:07:26 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 06:36:34 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils.h"

# define BUFFER_SIZE 64

char	*get_next_line(int fd);
int		check_for(char *buff, char c);
bool	parser(char *filename, t_info *inf);
bool	valid_map(char **map);
bool	has_ext(char *filename, char *ext);
t_type	match_type(char *s);
char	*match_type_str(t_type type);
bool	parse_map(int fd, t_info *inf);
bool	check_info(t_info *inf);
bool	check_ext(t_info *inf);
bool	should_parse_map(t_info *inf);
int		ft_map_height(char **map);
bool	only_ones_and_spaces(char *line);
bool	ft_check_symbols(char **map);
bool	ft_check_walls(char **map, int map_height);
bool	check_extremes(char *line);
bool	check_space_surroundings(char **map, unsigned int i, unsigned int j);
bool	parse_colors(t_info *inf);
void	extract_info(t_info *inf);

#endif
