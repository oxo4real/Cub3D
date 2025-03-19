/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:14:16 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/15 02:20:29 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	ft_lstadd_back(t_head *head, t_list *new_node)
{
	t_list	*last;

	if (!head || !new_node)
		return ;
	if (!head->head)
		head->head = new_node;
	else
	{
		last = head->last;
		last->next = new_node;
	}
	head->size++;
	head->last = new_node;
}
