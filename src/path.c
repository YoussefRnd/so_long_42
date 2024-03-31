/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 02:29:38 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/31 03:28:51 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

typedef struct s_reached
{
	int	reached_exit;
	int	reached_collectible;
}		t_reached;

void	flood_fill(t_game *game, int x, int y, t_reached *reached)
{
	if (x < 0 || y < 0 || y >= game->height || x >= game->width
		|| game->map[y][x] == '1' || game->map[y][x] == 'V')
		return ;
	game->map[y][x] = 'V';
	if (game->map[y][x] == 'E')
		reached->reached_exit = 1;
	if (game->map[y][x] == 'C')
		reached->reached_collectible += 1;
	flood_fill(game, x + 1, y, reached);
	flood_fill(game, x - 1, y, reached);
	flood_fill(game, x, y + 1, reached);
	flood_fill(game, x, y - 1, reached);
}

void	check_map_accessiblility(t_game *game)
{
	t_reached	*reached;

	reached = (t_reached *)malloc(sizeof(t_reached));
	if (!reached)
	{
		printf("Memory allocation failed");
		return ;
	}
	printf("Am I here?");
	reached->reached_collectible = 0;
	reached->reached_exit = 0;
	flood_fill(game, game->player.x, game->player.y, reached);
	if (!reached->reached_exit)
		printf("No exit");
	if (reached->reached_collectible != game->map_elements.collectible)
		printf("Not all element are accissible");
	free(reached);
}
