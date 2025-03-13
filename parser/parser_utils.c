/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:07:35 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/13 00:09:08 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	check_info(t_info *inf)
{
	int	i;

	i = 0;
	while (i < UNDEFINED)
	{
		if (!inf->data[i] || (inf->data[i] && !*(inf->data[i])))
			return (1);
		i++;
	}
	if (!inf->map)
		return (1);
	return (0);
}

bool	should_parse_map(t_info *inf)
{
	int	i;

	i = 0;
	while (i < UNDEFINED)
	{
		if (!inf->data[i])
			return (0);
		i++;
	}
	return (1);
}

bool	parse_map_helper(char **line, int *is_map, char **buff)
{
	char	*tmp;

	if (!str_empty(*line) && *is_map != -1)
	{
		*is_map = 1;
		tmp = ft_strjoin_deli(*buff, *line, "\x07");
		free(*buff);
		if (!tmp)
			return (free(*line), raise(MALLOC), 1);
		*buff = tmp;
	}
	else if (*is_map == 1)
		*is_map = -1;
	else if (*is_map == -1 && !str_empty(*line))
		return (free(*buff), free(*line), raise(INVALID_MAP), 1);
	return (0);
}

bool	parse_map(int fd, t_info *inf)
{
	char	*line;
	int		is_map;
	char	*buff;

	buff = ft_strdup("\x07");
	if (!buff)
		return (raise(MALLOC), 1);
	is_map = 0;
	while (1337)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parse_map_helper(&line, &is_map, &buff))
			return (1);
		free(line);
	}
	if (!is_map)
		return (free(buff), raise(NO_MAP), 1);
	inf->map = ft_split(buff, 0x7);
	free(buff);
	if (!inf->map)
		return (raise(MALLOC), 1);
	return (0);
}
