/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:23:02 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/13 17:09:34 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_SO_LONG_H
# define BONUS_SO_LONG_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define GAME "so_long"
# define IMG_SIZE 80

# define CYAN "\e[38;5;51m"
# define GREEN "\e[38;5;47m"
# define PURPLE "\e[38;5;219m"
# define RED "\e[38;5;124m"
# define YELLOW "\e[38;5;227m"
# define ESC "\033[0m"

# define EMPTY "../images/empty.xpm"
# define WALL "../images/wall.xpm"
# define COLLECTIBLE1 "../images/heart1.xpm"
# define COLLECTIBLE2 "../images/heart2.xpm"
# define MAN "../images/man.xpm"
# define WOMAN "../images/woman.xpm"
# define RIVAL1 "../images/broken_heart1.xpm"
# define RIVAL2 "../images/broken_heart2.xpm"
# define REWARDMM "../images/coupleMM.xpm"
# define REWARDWM "../images/coupleWM.xpm"
# define REWARDWW "../images/coupleWW.xpm"

# define MTOPE "The map contains more or less than one player/exit!\n"
# define MDNOC "The map does not contain at least one collectible!\n"
# define MCIC "The map contains invalid characters!\n"
# define MNRSW "The map is not a rectangle that is surrounded by walls!\n"
# define MDNVP "The map does not contain a valid path!\n"
# define AOFNV "The arguments are invalid or the format of the map is!\n"

typedef enum s_bool
{
	false = 0,
	true = 1
}			t_bool;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		mlx_wth;
	int		mlx_hgt;

	void	*img_wall;
	void	*img_empty;
	void	*img_exit;
	void	*img_player;
	void	*img_rival[2];
	void	*img_clt[2];
	void	*img_reward;
	int		img_wth;
	int		img_hgt;

	char	**map;
	int		map_wth;
	int		map_hgt;
	int		amt_player;
	int		amt_exit;
	int		amt_cmpnt;
	int		amt_clt;
	int		cnt_clt;
	int		player[2];
	int		snd_player[2];
	int		amt_moves;
	char	fst_char;
	char	snd_char;
	t_bool	won;
}				t_data;

int		create_map(t_data *game, char *map, char *player, char *exit);
int		select_characters(t_data *game, char *requested_player, char *requested_exit);
void	display_moves(t_data *game);
int		read_map(t_data *game, char *map);
t_bool	check_map(t_data *game);
int		free_map(t_data *game);
t_bool	check_path(t_data *game);
t_bool	error(int errnum, char *descr);
void	welcome_user(void);
void	create_images(t_data *game);
int		create_sprites(t_data *game);
int		play_game(int keycode, t_data *game);
void	put_image_to_window(t_data *game, char *rel_path, int row, int clm);
int		close_window(t_data *game);
void	congratulate_user(t_data *game);
void	game_over(t_data *game);

#endif
