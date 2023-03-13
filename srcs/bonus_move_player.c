/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:22:49 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/13 14:27:45 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	display_moves(t_data *game)
{
	char	*movements;
	char	*collected;

	mlx_put_image_to_window(game->mlx, game->window, game->img_wall, 0, 0);
	movements = ft_itoa(game->amt_moves);
	mlx_string_put(game->mlx, game->window, IMG_SIZE / 10, 23, 0, "Movements");
	mlx_string_put(game->mlx, game->window, IMG_SIZE / 2, 36, 0, movements);
	free (movements);
	collected = ft_itoa(game->cnt_clt);
	mlx_string_put(game->mlx, game->window, IMG_SIZE / 10, 49, 0, "Collected");
	mlx_string_put(game->mlx, game->window, IMG_SIZE / 2, 62, 0, collected);
	free (collected);
}

// Checks validity of requested move
static int	check_move(t_data *game, int player, int row, int clm)
{
	char		dst;

	dst = game->map[row][clm];
	if (dst == '1')
		return (0);
	if (player == 1)
		mlx_put_image_to_window(game->mlx, game->window, game->img_empty,
			game->player[1] * IMG_SIZE, game->player[0] * IMG_SIZE);
	else if (player == 2)
		mlx_put_image_to_window(game->mlx, game->window, game->img_empty,
			game->snd_player[1] * IMG_SIZE, game->snd_player[0] * IMG_SIZE);
	ft_printf(CYAN"Counter: %i\n"ESC, ++game->amt_moves);
	if (dst == 'C' && ++game->cnt_clt <= game->amt_clt)
	{
		ft_printf(GREEN"\nCollected: %i 🥳\n\n"ESC, game->cnt_clt);
		game->map[row][clm] = '0';
	}
	else if (dst == 'R')
		game_over(game);
	display_moves(game);
	return (1);
}

static void keycodes_first_player(int keycode, t_data *game)
{
	if (keycode == 123
		&& check_move(game, 1, game->player[0], game->player[1] - 1) == 1)
		game->player[1]--;
	else if (keycode == 124
		&& check_move(game, 1,game->player[0], game->player[1] + 1) == 1)
		game->player[1]++;
	else if (keycode == 125
		&& check_move(game, 1, game->player[0] + 1, game->player[1]) == 1)
		game->player[0]++;
	else if (keycode == 126
		&& check_move(game, 1, game->player[0] - 1, game->player[1]) == 1)
		game->player[0]--;
	mlx_put_image_to_window(game->mlx, game->window, game->img_player,
			game->player[1] * IMG_SIZE, game->player[0] * IMG_SIZE);
}

static void keycodes_second_player(int keycode, t_data *game)
{
	if (keycode == 0
		&& check_move(game, 2, game->snd_player[0], game->snd_player[1] - 1) == 1)
		game->snd_player[1]--;
	else if (keycode == 2
		&& check_move(game, 2, game->snd_player[0], game->snd_player[1] + 1) == 1)
		game->snd_player[1]++;
	else if (keycode == 1
		&& check_move(game, 2, game->snd_player[0] + 1, game->snd_player[1]) == 1)
		game->snd_player[0]++;
	else if (keycode == 13
		&& check_move(game, 2, game->snd_player[0] - 1, game->snd_player[1]) == 1)
		game->snd_player[0]--;
	mlx_put_image_to_window(game->mlx, game->window, game->img_exit,
			game->snd_player[1] * IMG_SIZE, game->snd_player[0] * IMG_SIZE);
}

// Creates hooks so that the user can control the player
int	play_game(int keycode, t_data *game)
{
	if (game->won == false)
	{
		keycodes_first_player(keycode, game);
		keycodes_second_player(keycode, game);
		if (game->player[0] == game->snd_player[0]
			&& game->player[1] == game->snd_player[1]
			&& game->cnt_clt == game->amt_clt)
			congratulate_user(game);
	}
	if (keycode == 53)
		return (close_window(game));
	return (1);
}
