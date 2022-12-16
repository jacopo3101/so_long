/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:39:24 by javellis          #+#    #+#             */
/*   Updated: 2022/10/24 16:39:28 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"../libft/libft.h"
#include <stdlib.h>

int	ft_print_format(t_print *tab, char *format, int pos)
{
	int	i;

	i = 0;
	if (format[pos] == 'c')
	{
		ft_putchar_fd(va_arg(tab->args, int), 1);
		i++;
	}
	else if (format[pos] == 's')
		i += ft_print_str(tab);
	else if (format[pos] == 'p')
		i += ft_print_ptr(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		i += ft_print_int(tab);
	else if (format[pos] == 'u')
		i += ft_print_unint(tab);
	else if (format[pos] == 'x')
		i += ft_hex_format(tab, 0);
	else if (format[pos] == 'X')
		i += ft_hex_format(tab, 32);
	else if (format[pos] == '%')
		i += write(1, "%", 1);
	return (i);
}

int	ft_print_str(t_print *tab)
{
	char	*str;
	int		len;

	str = va_arg(tab->args, char *);
	if (str == 0)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

int	ft_print_unint(t_print *tab)
{
	unsigned int	val;
	char			*nbr;

	val = va_arg(tab->args, unsigned int);
	nbr = ft_unsigned_itoa(val);
	ft_putstr_fd(nbr, 1);
	val = ft_strlen(nbr);
	free(nbr);
	return ((int)val);
}

int	ft_print_int(t_print *tab)
{
	int		i;
	int		val;
	int		len;
	char	*nbr;

	i = 0;
	val = va_arg(tab->args, int);
	nbr = ft_itoa(val);
	len = ft_strlen(nbr);
	if (tab->sign)
	{
		if (val >= 0)
		{
			ft_putchar_fd('+', 1);
			i++;
		}
	}
	else if (tab->sp && val >= 0)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putstr_fd(nbr, 1);
	free(nbr);
	return (i + len);
}
