/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:13:52 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/17 03:41:58 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	get_direction(char c)
{
	if (c == 'E')
		return (0);
	else if (c == 'W')
		return (M_PI);
	else if (c == 'S')
		return (M_PI_2);
	else
		return (3 * M_PI_2);
}
