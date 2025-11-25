/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:19:57 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/25 18:23:38 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "structs.h"
# include "libs/libft/libft.h"
# include "libs/gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>

void	handle_events(t_all *data);
void	clean_images(t_all *data);
void	images_to_window(t_all *data);
void	alocate_images(t_all *data);
void	search_npc(char *str, int height, t_all *data);
char	**dupmap(t_all *data);
char	**free_error_char(char **map);
int		move_up(t_all *data);
int		move_down(t_all *data);
int		move_left(t_all *data);
int		move_right(t_all *data);
int		movements(int keycode, t_all *data);
int		close_n_clean(t_all *data);
int		get_size(int fd, t_all *data);
int		free_error_int(char **map, int index, int h);
int		creating_map(t_all *data, int fd);
int		check_characters(char *str);
int		map_check_full(char *filename, t_all *data);
void	check_path(t_all *data);
int		final_check(char **map, int height, int length);
int		validate_flood(char **map, int h, int w);
void	flood_fill(char **map, int x, int y, int h, int w);
int		can_fill(char c);
int		check_closed(char **map, int height, int length);
void	free_loaded_images(t_all *data, int limit);
void	draw_row(t_all *data, int i);
void 	draw_column(t_all *data, int row);
int		check_many_cep(char **map, int height);

#endif