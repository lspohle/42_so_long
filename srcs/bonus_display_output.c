/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_display_output.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:22:39 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/14 08:58:55 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

// Display an error message for the user
t_bool	error(int errnum, char *descr)
{
	char	*select_characters;
	char	*available_characters;
	char	*select_map;
	char	*available_maps;
	char	*rules_map;

	select_characters = "\nPlease select the player you favor the most and choose an image that represents your loved one.";
	available_characters = "   - W (woman)\n   - M (man)\n   - O (others)\n";
	select_map = "\nPlease select the map you would like to play on.";
	available_maps = "   - ../maps/map1.ber\n   - ../maps/map2.ber\n   - ../maps/bonus_map1.ber\n   - ../maps/bonus_map2.ber\n   - ../maps/bonus_map3.ber\n   - ../maps/bonus_map4.ber\n   - ../maps/bonus_map5.ber\n";
	rules_map = "   - It must be rectangular.\n   - It must be surrounded by walls.\n   - It must contain exactly one exit.\n   - It must contain exactly one starting position.\n   - It must contain a valid path.\n   - It must contain at least one collectible.\n";
	ft_printf(RED"Error: "ESC"%s\n", strerror(errnum));
	ft_printf(RED"%s", descr);
	ft_printf(GREEN"%s"ESC"\nThose are the available characters:\n", select_characters);
	ft_printf(YELLOW"%s"ESC, available_characters),
	ft_printf(GREEN"%s"ESC"\nThose are the available maps:\n", select_map);
	ft_printf(YELLOW"%s"ESC, available_maps),
	ft_printf("The map has to be valid:\n"YELLOW"%s"ESC, rules_map);
	ft_printf("\nAn example is: "GREEN"alv ../maps/bonus_map2.ber M W\n\n"ESC);
	return (false);
}

// Welcomes the user
void	welcome_user(void)
{
	ft_printf(PURPLE"\n╔════════════════════════════════════╗\n");
	ft_printf(PURPLE"║"ESC"        Your on your way! ⛄️        "PURPLE"║\n");
	ft_printf(PURPLE"╚════════════════════════════════════╝\n\n"ESC);
}

// Congratulates the user
void	congratulate_user(t_data *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img_reward,
		game->player[1] * IMG_SIZE, game->player[0] * IMG_SIZE);
	ft_printf(PURPLE"\n╔════════════════════════════════════╗\n");
	ft_printf(PURPLE"║"GREEN"      🎉🥳 Congratulations! 🥳🎉    "PURPLE"║\n");
	ft_printf(PURPLE"╚════════════════════════════════════╝\n"ESC);
	game->won = true;
}

// Inform the user that the game is over
void	game_over(t_data *game)
{
	ft_printf(RED"\n╔════════════════════════════════════╗\n");
	ft_printf(RED"║"ESC"       Give it another try! 😉      "RED"║\n");
	ft_printf(RED"╚════════════════════════════════════╝\n\n"ESC);
	close_window(game);
}
