/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:26:51 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/28 03:03:54 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/Libft/libft.h"
# include "get_next_line.h"
# include <mlx.h>

typedef struct s_game
{
	int	height;
	int	width;
}		t_map;

typedef struct s_map
{
	int	wall;
	int	collectible;
	int	player;
	int	exit;
}		t_map;

#endif