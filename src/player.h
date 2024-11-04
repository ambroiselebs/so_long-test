/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 03:36:51 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/04 04:57:48 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../main.h"

typedef struct s_mouvement_params
{
	char			***map;
	t_player		*player;
	t_game_infos	*game_infos;
}	t_mouvement_params;

void	get_location(char ***map, t_game_infos *game_infos, t_player *player);
void	init_player(char ***map, t_game_infos *game_infos, t_player *player);
int		handle_player_mouvement(int key, t_mouvement_params *params);

#endif
