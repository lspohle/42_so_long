/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:22:52 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/10 10:39:24 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data		game;

	if (argc != 4)
		return (error(EINVAL, AOFNV));
	if (create_map(&game, argv[1], argv[2], argv[3]) == 0)
		return (0);
	welcome_user();
	mlx_key_hook(game.window, play_game, &game);
	mlx_hook(game.window, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (1);
}
