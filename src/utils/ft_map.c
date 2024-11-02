/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 03:26:38 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/02 04:58:29 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <stdlib.h>
#include <mlx.h>
#include <time.h>
#include <stdio.h>

void	init_map(char ***in_map, t_game_infos *game_infos)
{
	*in_map = malloc((game_infos->win_height * game_infos->img_size)
			* sizeof(char *));
	(*in_map)[0] = "1111111111111";
	(*in_map)[1] = "1002000000001";
	(*in_map)[2] = "1001110001111";
	(*in_map)[3] = "1000010000001";
	(*in_map)[4] = "1000011111001";
	(*in_map)[5] = "1000000000001";
	(*in_map)[6] = "1001000110001";
	(*in_map)[7] = "1111111111111";
}

void	free_map(char ***in_map, t_game_infos *game_infos)
{
	unsigned int	i;

	i = 0;
	while (i < game_infos->win_width)
		free((*in_map)[i++]);
	free((*in_map));
}

void	put_img(char id, t_game_infos *game_infos,
		unsigned int pos_x, unsigned int pos_y)
{
	if (id == '0')
		mlx_put_image_to_window(game_infos->mlx,
			game_infos->mlx_win, game_infos->back_sprite,
			pos_x, pos_y);
	if (id == '1')
		mlx_put_image_to_window(game_infos->mlx,
			game_infos->mlx_win, game_infos->wall_sprite,
			pos_x, pos_y);
}

void	draw_map(char ***in_map, t_game_infos *game_infos)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	pos_x;
	unsigned int	pos_y;

	y = 0;
	pos_y = 0;
	while (y < game_infos->win_height)
	{
		x = 0;
		pos_x = 0;
		while (x < game_infos->win_width)
		{
			put_img((*in_map)[y][x], game_infos, pos_x, pos_y);
			x++;
			pos_x += game_infos->img_size;
		}
		y++;
		pos_y += game_infos->img_size;
	}
}
