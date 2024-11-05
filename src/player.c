/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:29:18 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/05 17:24:42 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "mlx.h"
#include "utils/init.h"
#include <stdlib.h>
#include <stdio.h>

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
			if ((*map)[y][x] == 'P')
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

int	check_wall(t_mouvement_params *params, int *new_x, int *new_y)
{
	if ((*params->map)[*new_y][*new_x] == '1')
		return (1);
	if ((*params->map)[*new_y][*new_x] == 'C')
		params->game_infos->coin++;
	if ((*params->map)[*new_y][*new_x] == 'E')
	{
		if (params->game_infos->coin == params->game_infos->total_coint)
			exit_game(params->map, params->game_infos);
		return (1);
	}
	(*params->map)[params->player->pos_y][params->player->pos_x] = '0';
	params->player->pos_x = *new_x;
	params->player->pos_y = *new_y;
	(*params->map)[*new_y][*new_x] = 'P';
	return (0);
}

int	handle_player_mouvement(int key, t_mouvement_params *params)
{
	int	new_x;
	int	new_y;

	new_x = params->player->pos_x;
	new_y = params->player->pos_y;
	params->game_infos->counter++;
	if (key == 'd')
		new_x += params->player->speed;
	else if (key == 'a')
		new_x -= params->player->speed;
	else if (key == 's')
		new_y += params->player->speed;
	else if (key == 'w')
		new_y -= params->player->speed;
	else if (key == 65307)
		exit_game(params->map, params->game_infos);
	if (!check_wall(params, &new_x, &new_y))
		draw_map(params->map, params->game_infos, params->player);
	printf("%d\n", params->game_infos->counter);
	return (0);
}
