/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:56:23 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/02 01:59:00 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	xpm_to_img(t_game *game, char block)
{
	if (block == '1')
		game->img.img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/wall.xpm",
				&game->img.width, &game->img.height);
	else if (block == '0')
		game->img.img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm",
				&game->img.width, &game->img.height);
	else if (block == 'C')
		game->img.img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm",
				&game->img.width, &game->img.height);
	else if (block == 'E')
		game->img.img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm",
				&game->img.width, &game->img.height);
	else if (block == 'P')
		game->img.img = mlx_xpm_file_to_image(game->mlx_ptr, "assets/floor.xpm",
				&game->img.width, &game->img.height);
	if (game->img.img == NULL)
	{
		ft_putstr_fd("Error loading image\n", 2);
		exit(1);
	}
}

void	draw_pixels(t_game *game, char *line, int height)
{
	int	i;

	i = 0;
	while (line[i])
	{
		xpm_to_img(game, line[i]);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, i
			* PIXEL, height * PIXEL);
		i++;
	}
}
