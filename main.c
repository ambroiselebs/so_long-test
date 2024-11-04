/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 02:52:13 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/04 05:29:56 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "src/utils/init.h"
#include "src/player.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

/* int	update(t_update params)
{

} */

void	load_images(t_game_infos *game_infos)
{
	int	img_size;

	img_size = (int) game_infos->img_size;
	game_infos->wall_sprite = mlx_xpm_file_to_image(game_infos->mlx,
			"assets/wall.xpm",
			&img_size,
			&img_size);
	game_infos->back_sprite = mlx_xpm_file_to_image(game_infos->mlx,
			"assets/back.xpm",
			&img_size,
			&img_size);
}

int	main(void)
{
	t_game_infos		game_infos;
	t_player			player;
	t_mouvement_params	move_params;
	char				**in_map;

	init_window(&game_infos);
	load_images(&game_infos);
	init_map(&in_map, &game_infos);
	init_player(&in_map, &game_infos, &player);
	draw_map(&in_map, &game_infos, &player);
	move_params.map = &in_map;
	move_params.player = &player;
	move_params.game_infos = &game_infos;
	mlx_key_hook(game_infos.mlx_win, handle_player_mouvement, &move_params);
	mlx_loop(game_infos.mlx);
	return (0);
}
