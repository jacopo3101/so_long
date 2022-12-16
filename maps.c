/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:16 by javellis          #+#    #+#             */
/*   Updated: 2022/12/16 10:13:48 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	ft_validate_map(char **tab, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->check = ft_checkinit(ft_strlen(tab[0]));
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'C')
				game->check.collectable += 1;
			else if (tab[i][j] == 'P')
			{
				game->check.spawn += 1;
				game->check.start_x = i;
				game->check.start_y = j;
			}
			else if (tab[i][j] == 'E')
				game->check.exit += 1;
		}
	}
	j = ft_check_flags(&(game->check), ft_mapdup(tab), i);
	ft_print_error(game->check, j);
	return (j);
}

int	ft_check_flags2(char **tab, t_map_check *check)
{
	ft_path_find(tab, check, check->start_x, check->start_y);
	ft_free_map(tab);
	if (check->reachable_c != check->collectable)
		check->path = 0;
	if (check->spawn == 1 && check->exit == 1
		&& check->collectable >= 1 && check->path == 1
		&& check->collectable == check->reachable_c)
		return (1);
	else
		return (0);
}

int	ft_check_flags(t_map_check *check, char **tab_cpy, int tab_len)
{
	int	i;
	int	j;

	i = -1;
	while (tab_cpy[++i])
	{
		if (ft_strlen(tab_cpy[i]) != check->strlen)
		{
			check->strlen = -1;
			ft_free_map(tab_cpy);
			return (0);
		}
		j = -1;
		while (tab_cpy[i][++j])
		{
			if (tab_cpy[0][j] != '1' || tab_cpy[i][0] != '1'
				|| tab_cpy[i][ft_strlen(tab_cpy[i]) - 1] != '1'
				|| tab_cpy[tab_len - 1][j] != '1' || check->spawn != 1)
			{
				ft_free_map(tab_cpy);
				return (0);
			}
		}
	}
	return (ft_check_flags2(tab_cpy, check));
}

int	ft_path_find(char **tab, t_map_check *err, int x, int y)
{
	if (tab[x][y] == 'E')
	{
		err->path = 1;
		return (0);
	}
	if (tab[x][y] == 'C')
		err->reachable_c++;
	tab[x][y] = '1';
	if (tab[x + 1][y] != '1')
	{
		ft_path_find(tab, err, x + 1, y);
	}
	if (tab[x - 1][y] != '1')
	{
		ft_path_find(tab, err, x - 1, y);
	}
	if (tab[x][y + 1] != '1')
	{
		ft_path_find(tab, err, x, y + 1);
	}
	if (tab[x][y - 1] != '1')
	{
		ft_path_find(tab, err, x, y - 1);
	}
	return (0);
}
