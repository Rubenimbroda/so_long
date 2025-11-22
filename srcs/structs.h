/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 03:06:43 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/21 19:17:41 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct t_player
{
	int	moves;
	int	x;
	int	y;
}				t_player;

typedef struct t_map
{
	char	**map;
	int		w;
	int		h;
	int		many_colect;
	int		exit_x;
	int		exit_y;
}				t_map;

typedef struct s_imgs
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		w;
	int		h;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_imgs;

typedef struct s_win
{
	void	*mlx;
	void	*win;
}		t_win;

typedef struct s_all
{
	t_win		win;
	t_imgs		imgs[5];
	t_player	player;
	t_map		map;
}			t_all;

#endif
