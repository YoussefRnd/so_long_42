/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 23:07:01 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/30 01:52:52 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->map_elements.wall = 0;
	game->map_elements.player = 0;
	game->map_elements.collectible = 0;
	game->map_elements.exit = 0;
}

void	init_map(t_game *game, int fd)
{
	char *line;
	int i = 0;

	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	while ((line = get_next_line(fd)))
	{
		game->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map[i] = NULL;
}