/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:01:46 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/02 03:29:24 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_map_elements(t_game *game, char element)
{
	if (element == '1')
		game->map_elements.wall = 1;
	else if (element == 'P')
	{
		if (game->map_elements.player >= 1)
			handle_game_error(2);
		game->map_elements.player = 1;
	}
	else if (element == 'C')
		game->map_elements.collectible += 1;
	else if (element == 'E')
	{
		if (game->map_elements.exit >= 1)
			handle_game_error(3);
		game->map_elements.exit = 1;
	}
}
void	check_map_line(t_game *game, char *line, int check_wall,
		int is_last_line)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len -= 1;
	if (len != game->width)
		handle_game_error(4);
	while (line[i] && line[i] != '\n')
	{
		if ((i == 0 || i == len - 1) && line[i] != '1')
			handle_game_error(1);
		if ((check_wall || is_last_line) && line[i] != '1')
			handle_game_error(1);
		if (!check_wall && !is_last_line && line[i] != '1' && line[i] != '0'
			&& line[i] != 'P' && line[i] != 'C' && line[i] != 'E')
			handle_game_error(0);
		set_map_elements(game, line[i]);
		i++;
	}
}

void	check_map_elements(t_game *game)
{
	if (game->map_elements.player == 0)
		handle_game_error(5);
	if (game->map_elements.exit == 0)
		handle_game_error(5);
	if (game->map_elements.collectible == 0)
		handle_game_error(5);
}

void	read_map(t_game *game, int fd)
{
	char	*line;
	int		height;
	int		is_last_line;
	char	*next_line;

	height = 0;
	line = get_next_line(fd);
	while (line && *line)
	{
		next_line = get_next_line(fd);
		is_last_line = (next_line == NULL || *next_line == '\0');
		if (!height)
		{
			game->width = ft_strlen(line) - 1;
			check_map_line(game, line, 1, is_last_line);
		}
		else
			check_map_line(game, line, 0, is_last_line);
		height += 1;
		free(line);
		line = next_line;
	}
	game->height = height;
	check_map_elements(game);
	free(next_line);
}
