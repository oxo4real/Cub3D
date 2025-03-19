/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:20:04 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/19 02:35:45 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	get_rgb(u_int8_t r, u_int8_t g, u_int8_t b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

int	get_rgba(u_int8_t r, u_int8_t g, u_int8_t b, u_int8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
