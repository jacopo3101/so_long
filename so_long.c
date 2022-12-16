/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:44:43 by javellis          #+#    #+#             */
/*   Updated: 2022/12/15 12:11:31 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*path;
	char	**tab1;
	t_game	game;

	game.c_counter = 0;
	game.move = 0;
	game.frames = 0;
	path = "maps/map2.ber";
	if (argc == 2)
		path = argv[1];
	game.tab = ft_map_init(path);
	if (!game.tab)
		return (0);
	tab1 = ft_mapdup(game.tab);
	if (!ft_validate_map(tab1, &game))
	{
		ft_free_map(tab1);
		ft_free_map(game.tab);
		return (0);
	}
	ft_game_loop(game, tab1);
	return (0);
}

void	ft_game_loop(t_game game, char **tab)
{
	ft_free_map(tab);
	ft_game_init(&game);
	display_map(&game);
	mlx_hook(game.win, 17, 0, ft_close, &game);
	mlx_key_hook(game.win, ft_input, &game);
	mlx_loop_hook(game.mlx, render_frames, &game);
	mlx_loop(game.mlx);
	return ;
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
//valgrind -q --leak-check=full