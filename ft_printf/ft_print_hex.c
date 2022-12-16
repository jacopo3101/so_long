/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:00:02 by javellis          #+#    #+#             */
/*   Updated: 2022/10/24 15:00:05 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_printf.h"

int	ft_print_hex(unsigned int nbr, int offset)
{
	int	il;

	il = 1;
	if (nbr == 0)
		return (0);
	il += ft_print_hex(nbr / 16, offset);
	if (nbr % 16 > 9)
		ft_putchar_fd((nbr % 16 - 10) + ('a' - offset), 1);
	else
		ft_putchar_fd((nbr % 16) + '0', 1);
	return (il);
}

int	ft_hex_format(t_print *tab, int up_flag)
{
	int	val;
	int	i;

	i = 0;
	val = va_arg(tab->args, unsigned int);
	if (tab->hastag && up_flag && val != 0)
	{
		ft_putstr_fd("0X", 1);
		i += 2;
	}
	else if (tab->hastag && !up_flag && val != 0)
	{
		ft_putstr_fd("0x", 1);
		i += 2;
	}
	if (val == 0)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	else
		i += ft_print_hex(val, up_flag);
	return (i);
}

int	ft_print_hexptr(unsigned long long nbr)
{
	int	i;

	i = 1;
	if (nbr == 0)
		return (0);
	i += ft_print_hexptr(nbr / 16);
	if (nbr % 16 > 9)
		ft_putchar_fd((nbr % 16 - 10) + 'a', 1);
	else
		ft_putchar_fd((nbr % 16) + '0', 1);
	return (i);
}

int	ft_print_ptr(t_print *tab)
{
	int					i;
	unsigned long long	val;

	i = 0;
	val = va_arg(tab->args, unsigned long long);
	if (val == 0)
		i += write(1, "(nil)", 5);
	else
	{
		ft_putstr_fd("0x", 1);
		i += 2;
		i += ft_print_hexptr(val);
	}
	return (i);
}
