/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:11:27 by javellis          #+#    #+#             */
/*   Updated: 2022/10/05 12:11:30 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stddef.h>

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	int		i;
	char	*c;

	i = 0;
	c = malloc(nmemb * size);
	while ((unsigned int)i < nmemb)
	{
		c[i] = 0;
		i++;
	}
	return (c);
}
