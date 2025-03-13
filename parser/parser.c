/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:11:01 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/13 00:08:52 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parser_helper(t_info *inf, char *s)
{
	t_type	type;
	char	**tmp;

	if (str_empty(s))
		return (0);
	else
	{
		tmp = ft_split(s, ' ');
		if (!tmp)
			return (raise(MALLOC), 1);
		type = match_type(tmp[0]);
		if (type == UNDEFINED)
			return (freestrarr(&tmp), raise(MALFORMED_FILE), 1);
		if (inf->data[type])
			return (freestrarr(&tmp), raise(MALFORMED_FILE), 1);
		inf->data[type] = ft_strtrim_end(tmp[1]);
		freestrarr(&tmp);
	}
	return (0);
}

bool	parse_all(int fd, t_info *inf)
{
	char	*line;

	while (1337)
	{
		if (should_parse_map(inf))
		{
			if (parse_map(fd, inf))
				return (free_info(inf), 1);
			break ;
		}
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parser_helper(inf, line))
			return (free_info(inf), free(line), 1);
		free(line);
	}
	return (0);
}

bool	parser(char *filename)
{
	int		fd;
	t_info	inf;

	ft_bzero(&inf, sizeof(t_info));
	if (!has_ext(filename, ".cub"))
		return (raise(INVALID_FNAME), 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (p_error(filename, ""), 1);
	if (parse_all(fd, &inf))
		return (1);
	if (check_info(&inf))
		return (free_info(&inf), raise(MALFORMED_FILE), 1);
	if (!valid_map(inf.map))
		return (free_info(&inf), raise(INVALID_MAP), 1);
	free_info(&inf);
	return (0);
}
