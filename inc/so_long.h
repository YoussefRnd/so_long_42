/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:26:51 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/02 01:21:21 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/Libft/libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <stdbool.h>

# define PIXEL 64
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

typedef struct s_img
{
	int			*img;
	int			width;
	int			height;
}				t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	char		**map;
	t_map		map_elements;
	t_player	player;
	t_img		img;
}				t_game;

void			handle_game_error(int type);
void			read_map(t_game *game, int fd);
void			check_map_accessibility(t_game *game);
void			init_elements(t_game *game);
void			init_map(t_game *game, int fd);
void			init_mlx(t_game *game);
void			draw_pixels(t_game *game, char *line, int height);

#endif