/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:22:42 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/05/06 16:43:59 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptrsrc;

	if (c > 255)
		c -= 256;
	ptrsrc = (char *)s;
	while (*ptrsrc != c)
	{
		if (*ptrsrc == '\0')
		{
			return (NULL);
		}
		ptrsrc++;
	}
	return (ptrsrc);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = "boas pessoal";
	printf("%s\n", ft_strchr(str, 'b' + 256));
	printf("%s\n", strchr(str, 'b' + 256));
} */