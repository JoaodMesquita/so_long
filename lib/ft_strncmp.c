/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:54:52 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/08 10:40:41 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_p;
	unsigned char	*s2_p;

	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	i = 0;
	while (i < n && s1_p[i] && s2_p[i] && s1_p[i] == s2_p[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (s1_p[i] - s2_p[i]);
}
