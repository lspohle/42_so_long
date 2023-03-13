/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_create_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:22:30 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/13 13:21:13 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

// Puts images on the screen 
static void	put_images_to_window(t_data *game, int row, int clm)
{
	if (game->map[row][clm] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img_wall,
			clm * IMG_SIZE, row * IMG_SIZE);
	else if (game->map[row][clm] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->img_empty,
			clm * IMG_SIZE, row * IMG_SIZE);
	else if (game->map[row][clm] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->img_clt[0],
			clm * IMG_SIZE, row * IMG_SIZE);
	else if (game->map[row][clm] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->img_exit,
			clm * IMG_SIZE, row * IMG_SIZE);
	else if (game->map[row][clm] == 'R')
		mlx_put_image_to_window(game->mlx, game->window, game->img_rival[0],
			clm * IMG_SIZE, row * IMG_SIZE);
	else if (game->map[row][clm] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->img_player,
			clm * IMG_SIZE, row * IMG_SIZE);
}

//Puts the map on the screen image by image
static void	put_map_to_window(t_data *game)
{
	int	row;
	int	clm;

	row = -1;
	while (++row < game->map_hgt)
	{
		clm = -1;
		while (++clm < game->map_wth)
			put_images_to_window(game, row, clm);
	}
}

// Creates a window and ensures the connection between the window and the mlx
int	create_map(t_data *game, char *map, char *player, char *exit)
{
	ft_memset(game, 0, sizeof(t_data));
	if (read_map(game, map) == 0)
		return (0);
	else if (check_map(game) == false)
		return (free_map(game));
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->map_wth * IMG_SIZE, game->map_hgt * IMG_SIZE, GAME);
	if (select_characters(game, player, exit) == 0)
		return (error(EINVAL, AOFNV));
	create_images(game);
	put_map_to_window(game);
	display_moves(game);
	return (1);
}
