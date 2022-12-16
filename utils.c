/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:21 by javellis          #+#    #+#             */
/*   Updated: 2022/12/15 11:01:36 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		size;
	int			i;
	int			j;

	i = -1;
	j = 0;
	str = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	size = ft_strlen(s2) + ft_strlen(s1) + 1;
	str = (char *)malloc(size);
	if (!str)
		return (NULL);
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

t_map_check	ft_checkinit(int str_len)
{
	t_map_check	err;

	err.spawn = 0;
	err.exit = 0;
	err.collectable = 0;
	err.path = 0;
	err.strlen = str_len;
	err.start_x = 0;
	err.start_y = 0;
	err.reachable_c = 0;
	return (err);
}

void	ft_print_error(t_map_check err, int flag)
{
	if (!flag)
	{
		ft_printf("Error\n");
		if (err.strlen == -1)
		{
			ft_printf("Map file wrong shape\n");
			return ;
		}
		if (err.spawn != 1)
			ft_printf("Map files must constain one spawn point\n");
		if (err.exit != 1)
			ft_printf("Map files must constain one exit point\n");
		if (err.collectable < 1)
			ft_printf("Map files must constain at least one collectable\n");
		if (err.path != 1)
			ft_printf("Map files has no valid path\n");
	}
	return ;
}

char	**ft_mapdup(char **tab)
{
	char	**temp;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	while (tab[i])
		i++;
	while (tab[0][j])
		j++;
	j++;
	temp = malloc(sizeof(char *) * (i + 1));
	while (i > k)
	{
		temp[k] = malloc(sizeof(char) * j);
		ft_strlcpy(temp[k], tab[k], j);
		k++;
	}
	temp[k] = 0;
	return (temp);
}
