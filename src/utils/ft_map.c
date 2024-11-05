/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 03:26:38 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/05 17:16:54 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <stdlib.h>
#include <mlx.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

void	count_coin(char ***in_map, t_game_infos *game_infos)
{
	int	y;
	int	x;

	game_infos->total_coint = 0;
	y = 0;
	while (y < (int) game_infos->win_height)
	{
		x = 0;
		while (x < (int) game_infos->win_width)
		{
			if ((*in_map)[y][x] == 'C')
				game_infos->total_coint += 1;
			x++;
		}
		y++;
	}
}

void	free_map(char ***in_map, t_game_infos *game_infos)
{
	unsigned int	i;

	if (in_map == NULL || *in_map == NULL || game_infos == NULL)
		return ;
	i = 0;
	while (i < game_infos->win_height)
		free((*in_map)[i++]);
	free(*in_map);
	*in_map = NULL;
}

void	put_img(t_game_infos *game_infos, t_player *player,
		t_put_img_params params)
{
	if (params.id == '0')
		mlx_put_image_to_window(game_infos->mlx,
			game_infos->mlx_win, game_infos->back_sprite,
			params.pos_x, params.pos_y);
	else if (params.id == '1')
		mlx_put_image_to_window(game_infos->mlx,
			game_infos->mlx_win, game_infos->wall_sprite,
			params.pos_x, params.pos_y);
	else if (params.id == 'C')
		mlx_put_image_to_window(game_infos->mlx,
			game_infos->mlx_win, game_infos->coin_sprite,
			params.pos_x, params.pos_y);
	else if (params.id == 'E')
		mlx_put_image_to_window(game_infos->mlx,
			game_infos->mlx_win, game_infos->exit_sprite,
			params.pos_x, params.pos_y);
	else if (params.id == 'P')
		mlx_put_image_to_window(game_infos->mlx,
			game_infos->mlx_win, player->skin,
			params.pos_x, params.pos_y);
	else
		mlx_put_image_to_window(game_infos->mlx,
			game_infos->mlx_win, game_infos->back_sprite,
			params.pos_x, params.pos_y);
}

void	draw_map(char ***in_map, t_game_infos *game_infos, t_player *player)
{
	unsigned int		x;
	unsigned int		y;
	unsigned int		pos_x;
	unsigned int		pos_y;
	t_put_img_params	params;

	y = 0;
	pos_y = 0;
	while (y < game_infos->win_height)
	{
		x = 0;
		pos_x = 0;
		while (x < game_infos->win_width)
		{
			params.pos_x = pos_x;
			params.pos_y = pos_y;
			params.id = (*in_map)[y][x];
			put_img(game_infos, player, params);
			x++;
			pos_x += game_infos->img_size;
		}
		y++;
		pos_y += game_infos->img_size;
	}
}

void	init_map(char ***in_map, t_game_infos *game_infos)
{
	int	i;

	i = 0;
	*in_map = malloc(game_infos->win_height * sizeof(char *));
	while (i < (int) game_infos->win_height)
		(*in_map)[i++] = malloc((game_infos->img_size + 1) * sizeof(char));
	strcpy((*in_map)[0], "1111111111111");
	strcpy((*in_map)[1], "10010000000C1");
	strcpy((*in_map)[2], "1000011111001");
	strcpy((*in_map)[3], "1P0011E000001");
	strcpy((*in_map)[4], "1111111111111");
	count_coin(in_map, game_infos);
}
