/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:14:54 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/13 00:21:12 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// void	leaks(void)
// {
// 	system("leaks -q cub3d");
// }

int	main(int ac, char *av[])
{
	// atexit(leaks);
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
