/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:41:32 by javellis          #+#    #+#             */
/*   Updated: 2022/10/14 10:41:35 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->sign = 0;
	tab->sp = 0;
	tab->hastag = 0;
	tab->tl = 0;
	return (tab);
}

int	ft_format(t_print *tab, char *format, int pos)
{
	while (format[pos])
	{
		if (format[pos] == ' ')
		{
			tab->sp = 1;
			pos++;
		}
		else if (format[pos] == '+')
		{
			tab->sign = 1;
			pos++;
		}
		else if (format[pos] == '#')
		{
			tab->hastag = 1;
			pos++;
		}
		else
		{
			tab->tl = ft_print_format(tab, format, pos);
			break ;
		}
	}
	return (pos + 1);
}

int	ft_printf2(t_print *tab, char *format, int *i)
{
	int	res;

	res = 0;
	tab = ft_initialise_tab(tab);
	if (format[*i] == '%')
	{
		*i = ft_format(tab, (char *)format, *i + 1);
		res += tab->tl;
	}
	else
	{
		ft_putchar_fd(format[(*i)++], 1);
		res++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		res;

	i = 0;
	res = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	va_start(tab->args, format);
	if (!tab)
		return (-1);
	while (format[i])
	{
		res += ft_printf2(tab, (char *)format, &i);
	}
	va_end(tab->args);
	free(tab);
	return (res);
}
