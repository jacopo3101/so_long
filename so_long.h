/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:56:21 by javellis          #+#    #+#             */
/*   Updated: 2022/12/15 12:11:06 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <unistd.h>

typedef struct s_map_check {
	int	spawn;
	int	exit;
	int	collectable;
	int	path;
	int	strlen;
	int	start_x;
	int	start_y;
	int	reachable_c;
}				t_map_check;

typedef struct s_sprite {
	void	*reference;
	int		widht;
	int		height;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	char	*pixels;
	int		x;
	int		y;
}				t_sprite;

typedef struct s_anim_sprite
{
	t_sprite	frames[11];
	int			x;
	int			y;
}				t_anim_sprite;

typedef struct s_game {
	void				*mlx;
	void				*win;
	t_sprite			wall;
	t_sprite			pathway;
	t_sprite			enemy;
	t_sprite			collect;
	t_anim_sprite		pg;
	t_sprite			exit;
	char				**tab;
	int					c_counter;
	int					move;
	int					frames;
	t_map_check			check;
}				t_game;

char		*ft_strjoin(char *s1, char *s2);
char		**ft_map_init(char *path);
char		**ft_splitnl(char *str);
int			ft_validate_map(char **tab, t_game *game);
int			ft_path_find(char **tab, t_map_check *err, int x, int y);
char		**ft_mapdup(char **tab);
int			ft_check_flags(t_map_check *check, char **tab, int tab_len);
t_map_check	ft_checkinit(int str_len);
void		ft_print_error(t_map_check err, int flag);
void		ft_game_init(t_game *prog);
t_sprite	load_sprite(t_game game, char *path);
int			ft_input(int key_code, void *param);
void		display_map(t_game *game);
void		ft_move_char(t_game *game, int offset_y, int offset_x);
void		display_map2(t_game *game, int i, int j);
int			render_frames(void *param);
void		enemy_placement(char **tab);
void		enemy_movement(t_game *game);
int			ft_esc_hook(int keycode, t_game *game);
void		ft_move_enemy(t_game *game, int offset_y, int offset_x);
void		ft_free_map(char **map);
int			ft_close(t_game *game);
void		ft_game_loop(t_game game, char **tab);

#endif