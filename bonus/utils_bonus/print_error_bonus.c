/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:49:05 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static char	*get_error(t_error error)
{
	if (error == MALLOC)
		return ("MALLOC");
	else if (error == MALFORMED_FILE)
		return ("FILE");
	else if (error == INVALID_FNAME)
		return ("FILE");
	else if (error == NO_MAP)
		return ("MAP");
	else if (error == INVALID_MAP)
		return ("MAP");
	return ("ERROR");
}

static char	*get_error_msg(t_error error)
{
	if (error == MALLOC)
		return ("Cannot allocate!");
	else if (error == MALFORMED_FILE)
		return ("malformed file!");
	else if (error == INVALID_FNAME)
		return ("invalid filename!");
	else if (error == NO_MAP)
		return ("THERE IS NO MAP!");
	else if (error == INVALID_MAP)
		return ("invalid map!");
	else if (error == INVALID_EXT)
		return ("invalid filename extension!");
	else if (error == MLX)
		return ("MLX error!");
	return ("ERROR");
}

void	raise(t_error error)
{
	p_error(get_error(error), get_error_msg(error));
}

void	p_error(char *msg, char *details)
{
	ft_putendl_fd("ERROR", 2);
	if (!*details)
		perror(msg);
	else
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(details, 2);
	}
}
