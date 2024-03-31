/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 23:07:01 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/31 21:46:48 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * 64, game->height
			* 64, "so_long");
}

void	init_elements(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->map_elements.wall = 0;
	game->map_elements.player = 0;
	game->map_elements.collectible = 0;
	game->map_elements.exit = 0;
	game->map = NULL;
	game->player.x = 0;
	game->player.y = 0;
}

void	init_map(t_game *game, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	line = get_next_line(fd);
	while (*line && line)
	{
		game->map[i] = ft_strdup(line);
		j = 0;
		while (line[j])
		{
			if (line[j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
			}
			j++;
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
}
