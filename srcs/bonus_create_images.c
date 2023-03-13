/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_create_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:51:07 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/13 13:22:58 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

static int	select_player_and_exit(t_data *game, char *requested_player, char *requested_exit)
{
	if (ft_strncmp(requested_player, "W", sizeof("W")) == 0)
		game->img_player = mlx_xpm_file_to_image(game->mlx, WOMAN,
				&game->img_wth, &game->img_hgt);
	else if (ft_strncmp(requested_player, "O", sizeof("O")) == 0
			|| ft_strncmp(requested_player, "M", sizeof("M")) == 0)
		game->img_player = mlx_xpm_file_to_image(game->mlx, MAN,
				&game->img_wth, &game->img_hgt);
	else 
		return (0);
	if (ft_strncmp(requested_exit, "W", sizeof("W")) == 0)
		game->img_exit = mlx_xpm_file_to_image(game->mlx, WOMAN,
				&game->img_wth, &game->img_hgt);
	else if (ft_strncmp(requested_exit, "O", sizeof("O")) == 0
			|| ft_strncmp(requested_exit, "M", sizeof("M")) == 0)
		game->img_exit = mlx_xpm_file_to_image(game->mlx, MAN,
				&game->img_wth, &game->img_hgt);
	else
		return (0);
	return (1);
}

int select_characters(t_data *game, char *requested_player, char *requested_exit)
{
	if (select_player_and_exit(game, requested_player, requested_exit) == 0)
		return (0);
	if (ft_strncmp(requested_player, "W", sizeof("W")) == 0 && ft_strncmp(requested_exit, "W", sizeof("W")) == 0)
		game->img_reward = mlx_xpm_file_to_image(game->mlx, REWARDWW,
				&game->img_wth, &game->img_hgt);
	else if ((ft_strncmp(requested_player, "O", sizeof("O")) == 0
			|| ft_strncmp(requested_player, "M", sizeof("M")) == 0)
			&& (ft_strncmp(requested_exit, "O", sizeof("O")) == 0
			|| ft_strncmp(requested_exit, "M", sizeof("M")) == 0))
		game->img_reward = mlx_xpm_file_to_image(game->mlx, REWARDMM,
				&game->img_wth, &game->img_hgt);
	else if ((ft_strncmp(requested_player, "O", sizeof("O")) == 0
			|| (ft_strncmp(requested_player, "M", sizeof("M")) == 0
			&& ft_strncmp(requested_exit, "W", sizeof("W")) == 0))
			|| (ft_strncmp(requested_player, "W", sizeof("W")) == 0
			&& ft_strncmp(requested_exit, "O", sizeof("O")) == 0)
			|| ft_strncmp(requested_exit, "M", sizeof("M")) == 0)
		game->img_reward = mlx_xpm_file_to_image(game->mlx, REWARDWM,
				&game->img_wth, &game->img_hgt);
	else
		return (0);
	return (1);
}

// Creates every image once
void	create_images(t_data *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->img_wth, &game->img_hgt);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, EMPTY,
			&game->img_wth, &game->img_hgt);
	game->img_clt[0] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE1,
			&game->img_wth, &game->img_hgt);
	game->img_clt[1] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE2,
			&game->img_wth, &game->img_hgt);
	game->img_rival[0] = mlx_xpm_file_to_image(game->mlx, RIVAL1,
			&game->img_wth, &game->img_hgt);
	game->img_rival[1] = mlx_xpm_file_to_image(game->mlx, RIVAL2,
			&game->img_wth, &game->img_hgt);
}

// Creates the animation by looping through the map
int	create_sprites(t_data *game)
{
	static int	i;
	int			row;
	int			clm;

	usleep(100000);
	row = -1;
	while (++row < game->map_hgt)
	{
		clm = -1;
		while (++clm < game->map_wth)
		{
			if (game->map[row][clm] == 'R')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_rival[i], clm * IMG_SIZE, row * IMG_SIZE);
			else if (game->map[row][clm] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img_clt[i], clm * IMG_SIZE, row * IMG_SIZE);
		}
	}
	if (++i == 2)
		i = 0;
	return (1);
}
