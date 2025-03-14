/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:41:31 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/14 05:31:41 by mhayyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PI 3.14159265358979323846

typedef enum e_error
{
	MALLOC,
	MALFORMED_FILE,
	INVALID_FNAME,
	INVALID_MAP,
	NO_MAP
}		t_error;

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
void	freestrarr(char ***arr);
bool	is_space(char c);
char	*ft_strjoin_deli(char const *s1, char const *s2, char const *sep);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	p_error(char *msg, char *details);
void	raise(t_error error);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_trimmed_len(char const *s);
char	*ft_strtrim_end(char *s);
bool	str_empty(char *s);
uint8_t	ft_atou(const char *str);
bool	ft_isunint8(char *s);
size_t	ft_arr_len(char **strs);
char	*ft_strsjoin(char **strs, char *sep);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);
int		get_rgb(u_int8_t r, u_int8_t g, u_int8_t b);
bool	ato_color(char *s, int *co);
bool	ft_isdirection(char c);
double	get_direction(char c);

#endif
