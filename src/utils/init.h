/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 03:26:58 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/04 05:11:33 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../../main.h"

typedef struct s_put_img_params
{
	char			id;
	unsigned int	pos_x;
	unsigned int	pos_y;
}	t_put_img_params;

void	init_window(t_game_infos *game_infos);
void	init_map(char ***in_map, t_game_infos *game_infos);
void	put_img(t_game_infos *game_infos, t_player *player,
			t_put_img_params params);
void	draw_map(char ***in_map, t_game_infos *game_infos, t_player *player);
void	free_map(char ***in_map, t_game_infos *game_infos);

#endif
