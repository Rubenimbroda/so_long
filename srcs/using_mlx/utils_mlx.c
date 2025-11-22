/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 03:128:21 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/21 22:56:39 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	alocate_images(t_all *data)
{
	data->imgs[0].img_ptr = mlx_xpm_file_to_image(data->win.mlx,
			"textures/floor.xpm", &data->imgs[0].w, &data->imgs[0].h);
	data->imgs[1].img_ptr = mlx_xpm_file_to_image(data->win.mlx,
			"textures/wall.xpm", &data->imgs[1].w, &data->imgs[1].h);
	data->imgs[2].img_ptr = mlx_xpm_file_to_image(data->win.mlx,
			"textures/exit.xpm", &data->imgs[2].w, &data->imgs[2].h);
	data->imgs[3].img_ptr = mlx_xpm_file_to_image(data->win.mlx,
			"textures/player.xpm", &data->imgs[3].w, &data->imgs[3].h);
	data->imgs[4].img_ptr = mlx_xpm_file_to_image(data->win.mlx,
			"textures/collectable.xpm", &data->imgs[4].w, &data->imgs[4].h);
}

void	clean_images(t_all *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(data->win.mlx, data->imgs[i].img_ptr);
		i++;
	}
}

int	close_n_clean(t_all *data)
{
	clean_images(data);
	mlx_destroy_window(data->win.mlx, data->win.win);
	mlx_destroy_display(data->win.mlx);
	free (data->win.mlx);
	free_error_int(data->map.map, 0, data->map.h);
	exit (EXIT_SUCCESS);
}

void	images_to_window(t_all *data, int i)
{
	int	j;

	while (++i < data->map.h)
	{
		j = -1;
		while (++j < (data->map.w - 1))
		{
			if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->win.mlx, data->win.win,
					data->imgs[0].img_ptr, (j * 128), (i * 128));
			else if (data->map.map[i][j] == '1')
				mlx_put_image_to_window(data->win.mlx, data->win.win,
					data->imgs[1].img_ptr, (j * 128), (i * 128));
			else if (data->map.map[i][j] == 'E')
				mlx_put_image_to_window(data->win.mlx, data->win.win,
					data->imgs[2].img_ptr, (j * 128), (i * 128));
			else if (data->map.map[i][j] == 'P')
				mlx_put_image_to_window(data->win.mlx, data->win.win,
					data->imgs[3].img_ptr, (j * 128), (i * 128));
			else if (data->map.map[i][j] == 'C')
				mlx_put_image_to_window(data->win.mlx, data->win.win,
					data->imgs[4].img_ptr, (j * 128), (i * 128));
		}
	}
}
