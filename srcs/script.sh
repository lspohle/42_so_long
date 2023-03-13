# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 18:25:44 by lspohle           #+#    #+#              #
#    Updated: 2023/03/13 18:56:37 by lspohle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

cd ~/42_so_long/srcs && make bonus
echo "alias alv='cd ~/42_so_long/srcs && ./so_long'" >> ~/.zshrc
zsh