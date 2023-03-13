/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:59:39 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/08 22:05:50 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Loops through the array that outlines possible movements of the player
// Searches for a valid path 
// A path is only valid if player can reach all collectibles and the exit
static t_bool	search_for_path(t_data *game, t_bool **is_checked)
{
	int	amt_clt;
	int	amt_exit;
	int	row;
	int	clm;

	amt_clt = 0;
	amt_exit = 0;
	row = -1;
	while (++row < game->map_hgt)
	{
		clm = -1;
		while (++clm < game->map_wth)
		{
			if (game->map[row][clm] == 'C' && is_checked[row][clm] == true)
				amt_clt++;
			if (game->map[row][clm] == 'E' && is_checked[row][clm] == true)
				amt_exit++;
		}
	}
	if ((amt_clt + amt_exit) != (game->amt_clt + game->amt_exit))
		return (false);
	return (true);
}

// Loops through the map to mark all possible movements
static void	mark_path(t_data *game, int row, int clm, t_bool **is_checked)
{
	if (row < 0 || row >= game->map_hgt || clm < 0 || clm >= game->map_wth)
		return ;
	if (game->map[row][clm] != '1' && is_checked[row][clm] == false)
	{
		is_checked[row][clm] = true;
		mark_path(game, row, clm - 1, is_checked);
		mark_path(game, row, clm + 1, is_checked);
		mark_path(game, row + 1, clm, is_checked);
		mark_path(game, row - 1, clm, is_checked);
	}
}

// Check whether the map contains a valid path by looping through it
t_bool	check_path(t_data *game)
{
	t_bool	is_valid;
	t_bool	**is_checked;
	int		row;

	is_checked = (t_bool **)ft_calloc(game->map_hgt, sizeof(t_bool *));
	row = -1;
	while (++row < game->map_hgt)
		is_checked[row] = (t_bool *)ft_calloc(game->map_wth, sizeof(t_bool));
	mark_path(game, game->player[0], game->player[1], is_checked);
	is_valid = search_for_path(game, is_checked);
	while (--row >= 0)
		free(is_checked[row]);
	free(is_checked);
	return (is_valid);
}
