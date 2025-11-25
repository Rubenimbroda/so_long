/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:55:31 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/25 19:06:40 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_loaded_images(t_all *data, int limit)
{
	int	i;
	
	i = 0;
	while (i < limit)
	{
		if (data->imgs[i].img_ptr)
			mlx_destroy_image(data->win.mlx, data->imgs[i].img_ptr);
		i++;
	}
}

void	check_screen_size(t_all *data, int win_w, int win_h)
{
	mlx_get_screen_size(data->win.mlx, &data->win.size_x, &data->win.size_y);
	if  (win_w > data->win.size_x || win_h > data->win.size_y)
	{
		ft_printf("Error\nThis map is way too big!!\n");
		exit (1);
	}
}

void	init_window(t_all *data, int win_w, int win_h)
{
	data->win.mlx = mlx_init();
	if (!data->win.mlx)
		return ;
	data->win.win = mlx_new_window(data->win.mlx, win_w, win_h, "So_long");
	if (!data->win.win)
	{
		mlx_destroy_display(data->win.mlx);
		free(data->win.mlx);
		return ;
	}
}

void	handle_events(t_all *data)
{
	int	win_w;
	int	win_h;

	win_w = (data->map.w - 1) * 128;
	win_h = data->map.h * 128;
	ft_printf("Working 1");
	init_window(data, win_w, win_h);
	check_screen_size(data, win_w, win_h);
	alocate_images(data);
	ft_printf("Working 2");
	images_to_window(data);
	mlx_key_hook(data->win.win, &movements, data);
	mlx_hook(data->win.win, DestroyNotify, 0L, &close_n_clean, data);
	mlx_loop(data->win.mlx);
	close_n_clean(data);
}
