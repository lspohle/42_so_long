/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_read_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:22:57 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/09 07:22:16 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

// Establishes the wth of the map
static void	get_wth_of_map(t_data *game)
{
	while (game->map[0][game->map_wth] != '\0')
		game->map_wth++;
	if (game->map[0][game->map_wth - 1] == '\n')
		game->map_wth--;
}

// Adds the established line to the map
static int	add_line(t_data *game, char *line)
{
	char	**tmp;
	int		i;

	if (line == 0)
		return (0);
	i = 0;
	game->map_hgt++;
	tmp = (char **)malloc(sizeof(char *) * (game->map_hgt + 1));
	if (tmp == NULL)
		return (0);
	tmp[game->map_hgt] = NULL;
	while (i < game->map_hgt - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

// Checks whether the format of the map is ".ber"
static t_bool	check_format(char *map)
{
	char	*format;
	size_t	len;
	int		counter;

	format = ".ber";
	len = ft_strlen(map);
	counter = 4;
	while (--counter >= 0)
		if (map[--len] != format[counter])
			return (false);
	return (true);
}

// Reads the map line by line 
int	read_map(t_data *game, char *map)
{
	int		fd;
	char	*line;

	if (check_format(map) == false)
		return (error(EEXIST, "The format of the map is invalid!\n"));
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (error(ENOENT, ""));
	line = get_next_line(fd);
	if (line == 0)
		return (error(EEXIST, "The file is empty!\n"));
	while (line != 0)
	{
		if (add_line(game, line) == 0)
			break ;
		line = get_next_line(fd);
	}
	close (fd);
	get_wth_of_map(game);
	return (1);
}
