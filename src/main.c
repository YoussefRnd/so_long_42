/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:26:12 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/28 03:00:17 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	int	*mlx_ptr;
	int	*win_ptr;
	int	fd;

	int(argc);
	fd = open(argv[1], O_RDONLY);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "so_long");
	mlx_loop(win_ptr);
	return (0);
}
