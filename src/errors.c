/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:12:25 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/01 04:49:53 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	handle_game_error(int type)
{
	if (type == -1)
		ft_putstr_fd("The file does not exist\n", 2);
	else if (type == 0)
	{
		ft_putstr_fd("Only these characters are allowed in the map: ", 2);
		ft_putstr_fd("0, 1, P, C, E\n", 2);
	}
	else if (type == 1)
		ft_putstr_fd("The map must be surrounded by walls\n", 2);
	else if (type == 2)
		ft_putstr_fd("The map must have only one player\n", 2);
	else if (type == 3)
		ft_putstr_fd("The map must have only one exit\n", 2);
	else if (type == 4)
		ft_putstr_fd("The map should be a rectangle\n", 2);
	else if (type == 5)
	{
		ft_putstr_fd("The map must have at least one player,", 2);
		ft_putstr_fd("collectible and one exit\n", 2);
	}
	else if (type == 6)
		ft_putstr_fd("The map must have a valid path\n", 2);
	exit(1);
}
