/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_array_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:07:03 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

bool	lst_to_array(t_head *head, t_info *inf)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	tmp = head->head;
	inf->map = ft_calloc(head->size + 1, sizeof(char *));
	if (!inf->map)
		return (1);
	tmp = head->head;
	i = 0;
	while (tmp)
	{
		tmp2 = tmp->next;
		inf->map[i++] = tmp->line;
		free(tmp);
		tmp = tmp2;
	}
	return (0);
}
