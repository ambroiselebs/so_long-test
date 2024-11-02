/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 02:52:13 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/02 04:58:42 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "src/utils/init.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

/* int	update(t_update params)
{
	return (0);
} */

int	main(void)
{
	t_game_infos		game_infos;
	char				**in_map;
	int					img_size;

	init_window(&game_infos);
	img_size = (int) game_infos.img_size;
	game_infos.wall_sprite = mlx_xpm_file_to_image(game_infos.mlx,
			"assets/wall.xpm",
			&img_size,
			&img_size);
	game_infos.back_sprite = mlx_xpm_file_to_image(game_infos.mlx,
			"assets/back.xpm",
			&img_size,
			&img_size);
	init_map(&in_map, &game_infos);
	draw_map(&in_map, &game_infos);
	mlx_loop(game_infos.mlx);
	free_map(&in_map, &game_infos);
	return (0);
}
