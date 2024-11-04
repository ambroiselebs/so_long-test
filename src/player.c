/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:29:18 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/04 05:13:04 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "mlx.h"
#include "utils/init.h"
#include <stdio.h>
#include <stdlib.h>

void	get_location(char ***map, t_game_infos *game_infos, t_player *player)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game_infos->win_height)
	{
		x = 0;
		while (x < game_infos->win_width)
		{
			if ((*map)[y][x] == '2')
			{
				player->pos_x = x;
				player->pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_player(char ***map, t_game_infos *game_infos, t_player *player)
{
	int	img_size;

	img_size = (int) game_infos->img_size;
	get_location(map, game_infos, player);
	player->skin = mlx_xpm_file_to_image(game_infos->mlx,
			"assets/player.xpm",
			&img_size, &img_size);
	player->speed = 1;
}

int	handle_player_mouvement(int key, t_mouvement_params *params)
{
	if (key == 'd')
	{
		printf("%s\n", (*params->map)[params->player->pos_y]);
		(*params->map)[params->player->pos_y][params->player->pos_x] = '0';
		params->player->pos_x += params->player->speed;
		(*params->map)[params->player->pos_y][params->player->pos_x] = '2';
		draw_map(params->map, params->game_infos, params->player);
	}
	return (0);
}
