/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:40:41 by javellis          #+#    #+#             */
/*   Updated: 2022/10/12 15:40:47 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	else if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa2(int nbr, int i, char *str)
{
	if (nbr == -2147483648)
	{
		str[--i] = '8';
		nbr = -214748364;
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	i--;
	while (nbr > 0)
	{
		str[i--] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_itoa(int nbr)
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
