/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsiged_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:03:33 by javellis          #+#    #+#             */
/*   Updated: 2022/10/24 12:03:35 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"

static int	ft_len(unsigned int n)
{
	int	i;

	i = 1;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa2(unsigned int nbr, int i, char *str)
{
	i--;
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + 48;
		i--;
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_unsigned_itoa(unsigned int nbr)
{
	int		i;
	char	*str;

	i = ft_len(nbr);
	str = (char *)malloc(sizeof(char) * i);
	str[--i] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	return (ft_itoa2(nbr, i, str));
}
