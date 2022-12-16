/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:25 by javellis          #+#    #+#             */
/*   Updated: 2022/12/15 12:47:55 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_game *prog)
{
	int	i;

	i = 0;
	while (prog->tab[i])
		i++;
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx,
			ft_strlen(prog->tab[0]) * 65, i * 65, "so_long");
	prog->wall = load_sprite(*prog, "textures/iceTileset.xpm");
	prog->pathway = load_sprite(*prog, "textures/snowTileset.xpm");
	prog->enemy = load_sprite(*prog, "textures/sprite2.xpm");
	prog->collect = load_sprite(*prog, "textures/Cup.xpm");
	prog->pg.frames[0] = load_sprite(*prog, "textures/main/Idle1.xpm");
	prog->pg.frames[1] = load_sprite(*prog, "textures/main/Idle2.xpm");
	prog->pg.frames[2] = load_sprite(*prog, "textures/main/Idle3.xpm");
	prog->pg.frames[3] = load_sprite(*prog, "textures/main/Idle4.xpm");
	prog->pg.frames[4] = load_sprite(*prog, "textures/main/Idle5.xpm");
	prog->pg.frames[5] = load_sprite(*prog, "textures/main/Idle6.xpm");
	prog->pg.frames[6] = load_sprite(*prog, "textures/main/Idle7.xpm");
	prog->pg.frames[7] = load_sprite(*prog, "textures/main/Idle8.xpm");
	prog->pg.frames[8] = load_sprite(*prog, "textures/main/Idle9.xpm");
	prog->pg.frames[9] = load_sprite(*prog, "textures/main/Idle10.xpm");
	prog->pg.frames[10] = load_sprite(*prog, "textures/main/Idle11.xpm");
	prog->exit = load_sprite(*prog, "textures/door.xpm");
}

t_sprite	load_sprite(t_game game, char *path)
{
	t_sprite		s;
	void			*ref;
	char			*pix;

	ref = mlx_xpm_file_to_image(game.mlx, path, &s.widht, &s.height);
	pix = mlx_get_data_addr(ref, &s.bits_per_pixel, &s.line_size, &s.endian);
	s.reference = ref;
	s.pixels = pix;
	return (s);
}

int	render_frames(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->frames++;
	if (!(game->frames % 10000))
		display_map(game);
	if (!(game->frames % 100000))
		enemy_movement(game);
	return (0);
}

void	enemy_movement(t_game *game)
{
	int	i;

	i = rand() % 4;
	if (i == 0 && (game->tab[game->enemy.y][game->enemy.x + 1] == '0'
		|| game->tab[game->enemy.y][game->enemy.x + 1] == 'P'))
	{
		ft_move_enemy(game, 0, 1);
	}
	if (i == 1 && (game->tab[game->enemy.y][game->enemy.x - 1] == '0'
		|| game->tab[game->enemy.y][game->enemy.x - 1] == 'P'))
	{
		ft_move_enemy(game, 0, -1);
	}
	if (i == 2 && (game->tab[game->enemy.y + 1][game->enemy.x] == '0'
		|| game->tab[game->enemy.y + 1][game->enemy.x] == 'P'))
	{
		ft_move_enemy(game, 1, 0);
	}
	if (i == 3 && (game->tab[game->enemy.y - 1][game->enemy.x] == '0'
		|| game->tab[game->enemy.y - 1][game->enemy.x] == 'P'))
	{
		ft_move_enemy(game, -1, 0);
	}
}

void	ft_move_enemy(t_game *game, int offset_y, int offset_x)
{
	if (game->tab[game->enemy.y + offset_y][game->enemy.x + offset_x] == 'P')
		ft_close(game);
	game->tab[game->enemy.y + offset_y][game->enemy.x + offset_x] = 'N';
	game->tab[game->enemy.y][game->enemy.x] = '0';
}
