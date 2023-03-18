/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:22:39 by lspohle           #+#    #+#             */
/*   Updated: 2023/03/08 22:07:49 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Display an error message for the user
t_bool	error(int errnum, char *descr)
{
	ft_printf(RED"Error: "ESC"%s\n", strerror(errnum));
	ft_printf(RED"%s", descr);
	return (false);
}

// Welcomes the user
void	welcome_user(void)
{
	ft_printf(PURPLE"\n╔════════════════════════════════════╗\n");
	ft_printf(PURPLE"║"ESC"        Your on your way! ❤️        "PURPLE"║\n");
	ft_printf(PURPLE"╚════════════════════════════════════╝\n\n"ESC);
}

// Congratulates the user
void	congratulate_user(t_data *game)
{
	ft_printf(PURPLE"\n╔════════════════════════════════════╗\n");
	ft_printf(PURPLE"║"GREEN"      🎉🥳 Congratulations! 🥳🎉    "PURPLE"║\n");
	ft_printf(PURPLE"╚════════════════════════════════════╝\n"ESC);
	close_window(game);
}
