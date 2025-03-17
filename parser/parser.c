/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:11:01 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 05:52:32 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	skip_types(char **s, t_type type)
{
	int	i;

	i = 1 + (type < F);
	while (*s && i)
	{
		(*s)++;
		i--;
	}
	while (*s && is_space(**s))
		(*s)++;
}

bool	parser_helper(t_info *inf, char *s)
{
	t_type	type;

	skip_space(&s);
	type = match_type(s);
	if (type == UNDEFINED)
		return (raise(MALFORMED_FILE), 1);
	if (inf->data[type])
		return (raise(MALFORMED_FILE), 1);
	skip_types(&s, type);
	if (!*s)
		return (raise(MALFORMED_FILE), 1);
	inf->data[type] = ft_strtrim_end(s);
	if (!inf->data[type])
		return (raise(MALLOC), 1);
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
		if (!str_empty(line))
		{
			if (parser_helper(inf, line))
				return (free_info(inf), free(line), 1);
		}
		free(line);
	}
	return (0);
}

void	print_info(t_info *inf)
{
	int	i;
	int	_c;
	int	_f;

	i = 0;
	while (i < UNDEFINED)
	{
		printf("%s: %s\n", match_type_str(i), inf->data[i]);
		i++;
	}
	_c = inf->_c;
	_f = inf->_f;
	printf("F: (%d, %d, %d)\n", get_r(_f), get_g(_f), get_b(_f));
	printf("C: (%d, %d, %d)\n", get_r(_c), get_g(_c), get_b(_c));
	printf("C: %d\n", _c);
	printf("F: %d\n", _f);
}

bool	parser(char *filename, t_info *inf)
{
	int	fd;

	ft_bzero(inf, sizeof(t_info));
	if (!has_ext(filename, ".cub"))
		return (raise(INVALID_FNAME), 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (p_error(filename, ""), 1);
	if (parse_all(fd, inf))
		return (1);
	if (check_info(inf))
		return (free_info(inf), raise(MALFORMED_FILE), 1);
	if (!valid_map(inf->map))
		return (free_info(inf), raise(INVALID_MAP), 1);
	if (parse_colors(inf))
		return (free_info(inf), 1);
	print_info(inf);
	return (0);
}
