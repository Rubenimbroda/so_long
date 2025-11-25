/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 03:12:02 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/25 19:22:46 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void load_image(t_all *data, int i, char *path)
{
    int w;
    int h;
	
	w = 128;
	h = 128;
    data->imgs[i].img_ptr = mlx_xpm_file_to_image(data->win.mlx, path, &w, &h);
    if (!data->imgs[i].img_ptr)
    {
        free_loaded_images(data, i);
        ft_printf("Error\nInvalid texture file: ");
        write(2, path, ft_strlen(path));
        exit(1);
    }
    data->imgs[i].w = w;
    data->imgs[i].h = h;
}


void	alocate_images(t_all *data)
{
	load_image(data, 0, "textures/floor.xpm");
	load_image(data, 1, "textures/wall.xpm");
	load_image(data, 2, "textures/player.xpm");
	load_image(data, 3, "textures/collectable.xpm");
	load_image(data, 4, "textures/exit.xpm");
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

void images_to_window(t_all *data)
{
    int i = 0;

    while (i < data->map.h)
    {
        draw_column(data, i);
        i++;
    }
}

