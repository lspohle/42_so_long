/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:22:49 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/08 22:07:23 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks validity of requested move
static int	check_move(t_data *game, int row, int clm)
{
	char		dst;

	dst = game->map[row][clm];
	if (dst == '1')
		return (0);
	if (game->map[game->player[0]][game->player[1]] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->img_exit,
			game->player[1] * IMG_SIZE, game->player[0] * IMG_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->img_empty,
			game->player[1] * IMG_SIZE, game->player[0] * IMG_SIZE);
	ft_printf(CYAN"Counter: %i\n"ESC, ++game->amt_moves);
	if (dst == 'C' && ++game->cnt_clt <= game->amt_clt)
	{
		ft_printf(GREEN"\nCollected: %i 🥳\n\n"ESC, game->cnt_clt);
		game->map[row][clm] = '0';
	}
	return (1);
}

// Creates hooks so that the user can control the player
int	play_game(int keycode, t_data *game)
{
	if (keycode == 123
		&& check_move(game, game->player[0], game->player[1] - 1) == 1)
		game->player[1]--;
	else if (keycode == 124
		&& check_move(game, game->player[0], game->player[1] + 1) == 1)
		game->player[1]++;
	else if (keycode == 125
		&& check_move(game, game->player[0] + 1, game->player[1]) == 1)
		game->player[0]++;
	else if (keycode == 126
		&& check_move(game, game->player[0] - 1, game->player[1]) == 1)
		game->player[0]--;
	else if (keycode == 53)
		return (close_window(game));
	mlx_put_image_to_window(game->mlx, game->window, game->img_player,
		game->player[1] * IMG_SIZE, game->player[0] * IMG_SIZE);
	if (game->map[game->player[0]][game->player[1]] == 'E'
		&& game->cnt_clt == game->amt_clt)
		congratulate_user(game);
	return (1);
}
