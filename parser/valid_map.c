/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:27:22 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/18 22:17:09 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	valid_map(char **map)
{
	int	map_height;

	map_height = ft_map_height(map);
	if (map_height < 3 || !ft_check_symbols(map) || !ft_check_walls(map,
			map_height))
		return (false);
	return (true);
}

bool	ft_check_walls_helper(char *s1, char *s2)
{
	return (!only_ones_and_spaces(s1) || !only_ones_and_spaces(s2));
}

bool	ft_check_walls(char **map, int map_height)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_check_walls_helper(map[map_height - 1], map[0]))
		return (false);
	while (map[++i + 1])
	{
		if (!check_extremes(map[i]))
			return (false);
		if (!map[i][1])
			continue ;
		j = 0;
		while (map[i][++j + 1])
		{
			if ((j > (ft_strlen(map[i - 1]) - 1) || j > (ft_strlen(map[i + 1])
						- 1)) && map[i][j] != '1' && map[i][j] != ' ')
				return (false);
			if (!(j > (ft_strlen(map[i - 1]) - 1) || j > (ft_strlen(map[i + 1])
						- 1)) && map[i][j] == ' '
				&& !check_space_surroundings(map, i, j))
				return (false);
		}
	}
	return (true);
}

bool	ft_check_symbols(char **map)
{
	int	i;
	int	j;
	int	nplayer;

	nplayer = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S'
				|| map[i][j] == 'W')
				nplayer++;
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	if (nplayer == 1)
		return (true);
	return (false);
}
