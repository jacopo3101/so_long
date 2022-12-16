/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:04 by javellis          #+#    #+#             */
/*   Updated: 2022/12/15 12:21:26 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game *game)
{
	int	i;

	ft_free_map(game->tab);
	mlx_destroy_image(game->mlx, game->wall.reference);
	mlx_destroy_image(game->mlx, game->pathway.reference);
	mlx_destroy_image(game->mlx, game->enemy.reference);
	mlx_destroy_image(game->mlx, game->collect.reference);
	mlx_destroy_image(game->mlx, game->exit.reference);
	i = 0;
	while (i < 11)
	{
		mlx_destroy_image(game->mlx, game->pg.frames[i].reference);
		i++;
	}
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	exit(0);
}

int	ft_esc_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_close(game);
	return (0);
}

int	ft_input(int key_code, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_esc_hook(key_code, game);
	if (key_code == 119 && game->tab[game->pg.y - 1][game->pg.x] != '1')
	{
		ft_move_char(game, -1, 0);
		game->pg.y--;
	}
	else if (key_code == 97 && game->tab[game->pg.y][game->pg.x - 1] != '1')
	{
		ft_move_char(game, 0, -1);
		game->pg.x--;
	}
	else if (key_code == 115 && game->tab[game->pg.y + 1][game->pg.x] != '1')
	{
		ft_move_char(game, 1, 0);
		game->pg.y++;
	}
	else if (key_code == 100 && game->tab[game->pg.y][game->pg.x + 1] != '1')
	{
		ft_move_char(game, 0, 1);
		game->pg.x++;
	}
	return (0);
}

void	ft_move_char(t_game *game, int offset_y, int offset_x)
{
	if (game->tab[game->pg.y + offset_y][game->pg.x + offset_x] == 'C')
	{
		game->c_counter++;
	}
	else if (game->tab[game->pg.y + offset_y][game->pg.x + offset_x] == 'E')
	{
		if (game->c_counter == game->check.collectable)
			ft_close(game);
		else
			return ;
	}
	else if (game->tab[game->pg.y + offset_y][game->pg.x + offset_x] == 'N')
		ft_close(game);
	game->tab[game->pg.y][game->pg.x] = '0';
	game->tab[game->pg.y + offset_y][game->pg.x + offset_x] = 'P';
	game->move++;
}
