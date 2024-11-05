/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 03:26:38 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/05 17:21:48 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <stdlib.h>
#include <mlx.h>

void	init_window(t_game_infos *game_infos)
{
	game_infos->counter = 0;
	game_infos->coin = 0;
	game_infos->win_width = 13;
	game_infos->win_height = 5;
	game_infos->win_title = "so_long";
	game_infos->img_size = 50;
	game_infos->mlx = mlx_init();
	game_infos->mlx_win = mlx_new_window(game_infos->mlx,
			game_infos->win_width * game_infos->img_size,
			game_infos->win_height * game_infos->img_size,
			game_infos->win_title);
}
