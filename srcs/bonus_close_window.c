/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_close_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:22:44 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/14 10:08:47 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

// Frees the allocated map row by row
int	free_map(t_data *game)
{
	int	row;

	row = -1;
	if (game->map)
	{
		while (game->map[++row])
			free(game->map[row]);
		free(game->map);
	}
	return (0);
}

// Destroyes the window and created images accordingly 
int	close_window(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_empty);
	mlx_destroy_image(game->mlx, game->img_clt[0]);
	mlx_destroy_image(game->mlx, game->img_clt[1]);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_reward);
	mlx_destroy_image(game->mlx, game->img_tmp);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_rival[0]);
	mlx_destroy_image(game->mlx, game->img_rival[1]);
	mlx_destroy_window(game->mlx, game->window);
	free_map(game);
	exit(0);
}
