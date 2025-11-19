/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:42:13 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/19 15:46:33 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player(t_game *game)
{
	int	w;
	int	h;

	game->img_player = mlx_xpm_file_to_image
	(
		game->mlx, "assets/player.xpm",
		&w, &h
	);
	if (!game->img_player)
	{
		ft_printf("Error; no player image\n");
		exit(1);
	}
}