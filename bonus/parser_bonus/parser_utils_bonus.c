/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:07:35 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:08 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

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

bool	check_ext(t_info *inf)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!has_ext(inf->data[i], ".png"))
			return (1);
		i++;
	}
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

bool	parse_map_helper(char **line, int *is_map, t_head *head)
{
	t_list	*new;
	char	*tmp;

	if (!str_empty(*line) && *is_map != -1)
	{
		*is_map = 1;
		tmp = ft_strtrim_end(*line);
		if (!tmp)
			return (free(*line), ft_lstclear(&head->head), raise(MALLOC), 1);
		new = ft_lstnew(tmp);
		if (!new)
			return (free(tmp), free(*line), ft_lstclear(&head->head),
				raise(MALLOC), 1);
		ft_lstadd_back(head, new);
	}
	else if (*is_map == 1)
		*is_map = -1;
	else if (*is_map == -1 && !str_empty(*line))
		return (ft_lstclear(&head->head), free(*line), raise(INVALID_MAP), 1);
	return (0);
}

bool	parse_map(int fd, t_info *inf)
{
	char	*line;
	int		is_map;
	t_head	head;

	is_map = 0;
	head.head = NULL;
	head.last = NULL;
	head.size = 0;
	while (1337)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parse_map_helper(&line, &is_map, &head))
			return (1);
		free(line);
	}
	if (!is_map)
		return (ft_lstclear(&head.head), raise(NO_MAP), 1);
	if (lst_to_array(&head, inf))
		return (ft_lstclear(&head.head), raise(MALLOC), 1);
	return (0);
}
