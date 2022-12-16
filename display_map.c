/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:18:22 by javellis          #+#    #+#             */
/*   Updated: 2022/12/15 12:18:36 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_game *game)
{
	int		i;
	int		j;
	char	*mv;
	char	*n_move;

	n_move = ft_itoa(game->move);
	mv = ft_strjoin(ft_strdup("moves : "), n_move);
	i = -1;
	mlx_clear_window(game->mlx, game->win);
	while (game->tab[++i])
	{
		j = -1;
		while (game->tab[i][++j])
		{
			if (game->tab[i][j] == '1')
				mlx_put_image_to_window(game->mlx,
					game->win, game->wall.reference, j * 65, i * 65);
			else
				display_map2(game, i, j);
		}
	}
	mlx_string_put(game->mlx, game->win, 7, 20, 0, mv);
	free(n_move);
	free(mv);
}

void	display_map2(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx,
		game->win, game->pathway.reference, j * 65, i * 65);
	if (game->tab[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.reference, (j * 65) + 15, (i * 65) + 15);
	if (game->tab[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect.reference, (j * 65) + 20, (i * 65) + 30);
	if (game->tab[i][j] == 'N')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.reference, (j * 65) + 10, (i * 65) + 15);
		game->enemy.x = j;
		game->enemy.y = i;
	}
	if (game->tab[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->pg.frames[game->frames % 11].reference,
			j * 65 + 10, i * 65 + 10);
		game->pg.x = j;
		game->pg.y = i;
	}
}
