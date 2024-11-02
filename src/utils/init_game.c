/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 03:26:38 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/02 04:25:06 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <stdlib.h>
#include <mlx.h>

void	init_window(t_game_infos *game_infos)
{
	game_infos->win_width = 13;
	game_infos->win_height = 8;
	game_infos->win_title = "so_long";
	game_infos->img_size = 50;
	game_infos->mlx = mlx_init();
	game_infos->mlx_win = mlx_new_window(game_infos->mlx,
			game_infos->win_width * game_infos->img_size,
			game_infos->win_height * game_infos->img_size,
			game_infos->win_title);
}
