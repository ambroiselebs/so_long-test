/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 02:53:15 by aberenge          #+#    #+#             */
/*   Updated: 2024/11/04 05:11:37 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_player
{
	int				pos_x;
	int				pos_y;
	int				speed;
	void			*skin;
}	t_player;

typedef struct s_game_infos
{
	void			*mlx;
	void			*mlx_win;
	unsigned int	win_width;
	unsigned int	win_height;
	char			*win_title;
	char			**map;
	unsigned int	img_size;
	void			*wall_sprite;
	void			*back_sprite;
	t_player		*player;
}	t_game_infos;

typedef struct s_update
{
	t_game_infos	*game_infos;
	t_player		*player;
}	t_update;

void	init_window(t_game_infos *game_infos);
void	init_map(char ***in_map, t_game_infos *game_infos);

#endif
