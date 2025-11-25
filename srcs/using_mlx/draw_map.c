/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:07:06 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/25 18:26:20 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void draw_column(t_all *data, int row)
{
    int col = 0;
    int img_w;
	int	img_h;
    int tile_index;

    while (col < data->map.w)
    {
        if (data->map.map[row][col] == '0')
			tile_index = 0;
        else if (data->map.map[row][col] == '1')
			tile_index = 1;
        else if (data->map.map[row][col] == 'P')
			tile_index = 2;
        else if (data->map.map[row][col] == 'C')
			tile_index = 3;
        else
			tile_index = 4;

        img_w = data->imgs[tile_index].w;
        img_h = data->imgs[tile_index].h;

        mlx_put_image_to_window(data->win.mlx, data->win.win,
            data->imgs[tile_index].img_ptr, col * img_w, row * img_h);
        col++;
    }
}

void draw_map(t_all *data)
{
    int row = 0;

    while (row < data->map.h)
    {
        draw_column(data, row);
        row++;
    }
}
