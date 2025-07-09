/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:45:20 by joapedro          #+#    #+#             */
/*   Updated: 2025/07/08 12:32:28 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!*to_find)
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j])
		{
			j++;
		}
		if (!to_find[j])
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char	str[] = "joaopedro";
	char	to_find[] = "a";
	char	*resultado;

	resultado = ft_strstr(str, to_find);
	
	if (resultado)
	{
		printf("String encontrada - %s", resultado);
	}
	else
	{
		printf("String not found");
	}
	return (0);
}*/
