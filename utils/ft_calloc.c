/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:43:09 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/12 05:41:59 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*aloc;

	size *= count;
	aloc = malloc(size);
	if (aloc)
		ft_bzero(aloc, size);
	return (aloc);
}
