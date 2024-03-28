/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:01:46 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/28 23:18:05 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_map(t_game *game, char *line, int check_wall)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(line);
	if (len != game->width)
		handle_game_error(5);
	while (line[i] && line[i] != '\n')
	{
		if ((i == 0 || i == len - i) && line[i] != 1)
			handle_game_error(1);
		if (check_wall == 1 && line[i] != 1)
			handle_game_error(1);
		if (line[i] != 1 && line[i] != 0 && line[i] != 'P' && line[i] != 'C'
			&& line[i] != 'E')
			handle_game_error(0);
		i++;
	}
}

void	read_map(t_game *game, int fd)
{
	char *line;
	int height = 0;

	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!height)
		{
			game->width = ft_strlen(line);
			check_map(game, line, 1);
		}
		else
			check_map(game, line, 0);
		height += 1;
		free(line);
	}
	game->height = height;
}