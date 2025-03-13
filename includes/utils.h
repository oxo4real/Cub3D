/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhayyoun <mhayyoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:41:31 by mhayyoun          #+#    #+#             */
/*   Updated: 2025/03/13 00:05:13 by mhayyoun         ###   ########.fr       */
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

#endif
