/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:38:06 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/09 11:27:25 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_printf(const char *format, ...);
int		ft_unsigned_putnbr(unsigned int n);
int		ft_puthexa(unsigned long n);
int		ft_puthexa_big(unsigned long n);
int		ft_pointer(void *ptr);
char	*get_next_line(int fd);
int		gnl_ft_strlen(char *s);
char	*gnl_ft_strchr(char *s, int c);
char	*ft_strjoin(char *line, char *read_buffer);
void	shift(char *read_buffer);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strstr(char *str, char *to_find);

#endif
