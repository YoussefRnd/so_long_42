/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:26:51 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/31 03:22:20 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/Libft/libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <stdbool.h>
typedef struct s_map
{
	int			wall;
	int			collectible;
	int			player;
	int			exit;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_game
{
	int			height;
	int			width;
	char		**map;
	t_map		map_elements;
	t_player	player;
}				t_game;

void			handle_game_error(int type);
void			read_map(t_game *game, int fd);
void			check_map_accessiblility(t_game *game);

#endif