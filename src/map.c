/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:01:46 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/29 03:57:37 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_map(t_game *game, char element)
{
	if (element == '1')
		game->map_element.wall = 1;
	else if (element == 'P')
	{
		if (game->map_element.player >= 1)
			handle_game_error(2);
		game->map_element.player = 1;
	}
	else if (element == 'C')
		game->map_element.collectible += 1;
	else if (element == 'E')
	{
		if (game->map_element.exit >= 1)
			handle_game_error(3);
		game->map_element.exit = 1;
	}
}

void	check_map(t_game *game, char *line, int check_wall)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len -= 1;
	if (len != game->width)
		handle_game_error(5);
	while (line[i] && line[i] != '\n')
	{
		if ((i == 0 || i == len - i) && line[i] != '1')
			handle_game_error(1);
		if (check_wall == 1 && line[i] != '1')
			handle_game_error(1);
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'C'
			&& line[i] != 'E')
			handle_game_error(0);
		i++;
	}
	set_map(game, line[i]);
}

void	read_map(t_game *game, int fd)
{
	char *line;
	int height = 0;
	game = malloc(sizeof(t_game));
	while (true)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		if (!height)
		{
			game->width = ft_strlen(line) - 1;
			check_map(game, line, 1);
		}
		else
			check_map(game, line, 0);
		height += 1;
		free(line);
	}
	game->height = height;
}