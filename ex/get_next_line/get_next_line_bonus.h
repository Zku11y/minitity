/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:24:43 by oel-mado          #+#    #+#             */
/*   Updated: 2024/12/19 20:10:50 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

char	*rdd(char *buff, int fd);
char	*one_line(const char *buff);
char	*updtt(char *buff);

char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *who);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);

#endif //GET_NEXT_LINE_BONUS_H
