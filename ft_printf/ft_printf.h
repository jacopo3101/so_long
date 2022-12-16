/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:32:12 by javellis          #+#    #+#             */
/*   Updated: 2022/10/04 10:32:17 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include<unistd.h>

typedef struct s_print
{
	va_list	args;
	int		tl;
	int		sign;
	int		sp;
	int		hastag;
}	t_print;

int			ft_checkchr(const char *s, char c);
int			ft_print_format(t_print *tab, char *format, int pos);
t_print		*ft_initialise_tab(t_print *tab);
int			ft_format(t_print *tab, char *format, int pos);
int			ft_printf(const char *format, ...);
int			ft_print_char(t_print *tab);
int			ft_print_int(t_print *tab);
int			ft_print_str(t_print *tab);
int			ft_print_hex(unsigned int nbr, int offset);
int			ft_hex_format(t_print *tab, int up_flag);
int			ft_print_hexptr(unsigned long long nbr);
int			ft_print_ptr(t_print *tab);
int			ft_print_unint(t_print *tab);
int			ft_print_int(t_print *tab);
char		*ft_unsigned_itoa(unsigned int nbr);
int			ft_printf2(t_print *tab, char *format, int *i);

#endif
