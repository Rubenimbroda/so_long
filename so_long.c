/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:43:36 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/27 18:31:11 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long maps/(...).ber\n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	game.map = parse_map(argv[1]);
	if (!game.map)
		return (ft_printf("Error\nMap Invalid\n"), 1);
	if (!validate_map(&game))
		return (free_map(game.map), 1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			128 * map_width(game.map), 128 * map_height(game.map), "so_long");
	load_images(&game);
	find_player(&game);
	count_collectibles(&game);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game); // para moverse
	mlx_hook(game.win, 17, 0, close_game, &game); // evento para cerrar ventana
	mlx_loop(game.mlx); // motor del juego, hace que se mantenga abierto hasta que se acaba o se cierra
}
