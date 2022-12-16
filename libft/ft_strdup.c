/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:51:54 by javellis          #+#    #+#             */
/*   Updated: 2022/10/05 13:51:58 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*dup;

	size = ft_strlen(s) + 1;
	dup = malloc(size);
	if (dup == 0)
		return (NULL);
	ft_strlcpy(dup, (char *)s, size);
	return (dup);
}
