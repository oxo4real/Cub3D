/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:26:52 by aaghzal           #+#    #+#             */
/*   Updated: 2025/03/13 00:11:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_map_height(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

bool	only_ones_and_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	check_extremes(char *line)
{
	size_t	len;
	int		i;

	len = ft_strlen(line);
	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
		return (false);
	while (line[--len] == ' ')
		continue ;
	if (line[len] != '1')
		return (false);
	return (true);
}

bool	check_space_surroundings(char **map, unsigned int i, unsigned int j)
{
	if (map[i][j - 1] != ' ' && map[i][j - 1] != '1')
		return (false);
	if (map[i][j + 1] && map[i][j + 1] != ' ' && map[i][j + 1] != '1')
		return (false);
	if (map[i + 1][j] != ' ' && map[i + 1][j] != '1')
		return (false);
	if (map[i - 1][j] != ' ' && map[i - 1][j] != '1')
		return (false);
	return (true);
}
