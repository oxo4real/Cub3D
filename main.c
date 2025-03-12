/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:14:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/12 16:43:33 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(int ac, char *av[])
{
	(void)av;
	if (ac != 2)
	{
		printf("Usage: %s <map>.cub\n", av[0]);
		return (1);
	}
	if (parser(av[1]))
		return (1);
	return (0);
}
