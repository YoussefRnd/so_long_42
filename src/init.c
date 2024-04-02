/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 23:07:01 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/01 19:34:06 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_putstr_fd("Error initializing mlx\n", 2);
		exit(1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * PIXEL,
			game->height * PIXEL, "so_long");
	if (game->win_ptr == NULL)
	{
		ft_putstr_fd("Error creating window\n", 2);
		exit(1);
	}
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
	game->img.height = 0;
	game->img.width = 0;
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
		draw_pixels(game, line, i);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
}
