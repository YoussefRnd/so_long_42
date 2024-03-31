/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:26:12 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/31 21:48:04 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc > 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	init_elements(&game);
	read_map(&game, fd);
	close(fd);
	init_mlx(&game);
	fd = open(argv[1], O_RDONLY);
	init_map(&game, fd);
	close(fd);
	check_map_accessibility(&game);
	// mlx_loop(win_ptr);
	return (0);
}
