/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:19:26 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/09 10:13:03 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks whether the map is a rectangle that is surrounded by walls
static t_bool	check_edges(t_data *game)
{
	int	row;
	int	clm;

	row = -1;
	while (++row < game->map_hgt)
	{
		if (game->map[row][0] != '1' ||
			game->map[row][game->map_wth - 1] != '1')
			return (false);
	}
	clm = -1;
	while (++clm < game->map_wth)
	{
		if (game->map[0][clm] != '1' ||
			game->map[game->map_hgt - 1][clm] != '1' )
			return (false);
	}
	return (true);
}

// Checks whether the map is a rectangle
static t_bool	check_width(t_data *game)
{
	int	row;

	row = -1;
	while (++row < game->map_hgt)
	{
		if (game->map[row][game->map_wth] != '\n' &&
			game->map[row][game->map_wth] != '\0')
			return (false);
	}
	return (true);
}

// Ensures that the map contains the correct amount of characters
static void	count_components(t_data *game)
{
	int	row;
	int	clm;

	row = -1;
	while (++row < game->map_hgt)
	{
		clm = -1;
		while (++clm < game->map_wth)
		{
			if (game->map[row][clm] == 'E')
				game->amt_exit++;
			else if (game->map[row][clm] == 'C')
				game->amt_clt++;
			else if (game->map[row][clm] == 'P')
			{
				game->amt_player++;
				game->player[0] = row;
				game->player[1] = clm;
			}
			if (game->map[row][clm] == '1' || game->map[row][clm] == '0' ||
				game->map[row][clm] == 'C' || game->map[row][clm] == 'E' ||
				game->map[row][clm] == 'P')
				game->amt_cmpnt++;
		}
	}
}

// Checks the map step by step
t_bool	check_map(t_data *game)
{
	count_components(game);
	if (game->amt_player != 1 || game->amt_exit != 1)
		return (error(EINVAL, MTOPE));
	else if (game->amt_clt < 1)
		return (error(EINVAL, MDNOC));
	else if (game->amt_cmpnt != (game->map_wth) * (game->map_hgt))
		return (error(EINVAL, MCIC));
	else if (check_edges(game) == false || check_width(game) == false)
		return (error(EINVAL, MNRSW));
	else if (check_path(game) == false)
		return (error(EINVAL, MDNVP));
	return (true);
}
