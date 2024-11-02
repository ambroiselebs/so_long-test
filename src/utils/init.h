/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 03:26:58 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/02 04:57:54 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../../main.h"

void	init_window(t_game_infos *game_infos);
void	init_map(char ***in_map, t_game_infos *game_infos);
void	put_img(char id, t_game_infos *game_infos,
			unsigned int pos_x, unsigned int pos_y);
void	draw_map(char ***in_map, t_game_infos *game_infos);
void	free_map(char ***in_map, t_game_infos *game_infos);

#endif
