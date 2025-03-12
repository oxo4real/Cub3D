/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:11:01 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/12 15:44:27 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

bool	has_ext(char *filename, char *ext)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(filename);
	len2 = ft_strlen(ext);
	if (len1 <= len2)
		return (0);
	return (ft_strcmp(&filename[len1 - len2], ext) == 0);
}

bool	parser(char *filename)
{
	int		fd;
	char	*line;

	if (!has_ext(filename, ".cub"))
		return (printf("ERROR\n%s: invalid filename\n", filename), 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror(filename), 1);
	while (1337)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}
