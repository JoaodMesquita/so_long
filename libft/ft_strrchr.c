/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:47:36 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/08 12:43:29 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	c = (unsigned char)c;
	while (i >= 0)
	{
		if (s[i] == c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (0);
}
