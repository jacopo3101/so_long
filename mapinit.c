/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:36:49 by javellis          #+#    #+#             */
/*   Updated: 2022/12/15 12:38:41 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_init(char *path)
{
	int		fd;
	int		readed;
	char	*buffer;
	char	*str;
	char	**tab;

	fd = open(path, O_RDWR);
	if (fd < 0)
		return (NULL);
	readed = 1;
	buffer = ft_calloc(sizeof(char), 2);
	str = ft_calloc(sizeof(char), 1);
	while (readed != 0)
	{
		readed = read(fd, buffer, 1);
		buffer[readed] = '\0';
		str = ft_strjoin(str, buffer);
	}
	tab = ft_splitnl(str);
	enemy_placement(tab);
	free(buffer);
	free(str);
	close(fd);
	return (tab);
}

void	enemy_placement(char **tab)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = ft_strlen(tab[0]);
	y = 0;
	while (tab[y])
		y++;
	i = rand() % x;
	j = rand() % y;
	while (1)
	{
		if (tab[j][i] != '1' && tab[j][i] != 'C'
			&& tab[j][i] != 'E' && tab[j][i] != 'P')
		{
			tab[j][i] = 'N';
			break ;
		}
		i = rand() % x + 1;
		j = rand() % y + 1;
	}
}
