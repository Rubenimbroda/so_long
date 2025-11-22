/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:55:31 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/21 22:56:35 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_events(t_all *data)
{
	data->win.mlx = mlx_init();
	if (data->win.mlx == NULL)
		return ;
	data->win.win = mlx_new_window(data->win.mlx, ((data->map.w - 1) * 128),
			(data->map.h * 128), "So_long");
	if (data->win.win == NULL)
	{
		mlx_destroy_display(data->win.mlx);
		free(data->win.mlx);
		return ;
	}
	alocate_images(data);
	images_to_window(data, -1);
	mlx_key_hook(data->win.win, &movements, data);
	mlx_hook(data->win.win, DestroyNotify, 0L, &close_n_clean, data);
	mlx_loop(data->win.mlx);
	close_n_clean(data);
}
