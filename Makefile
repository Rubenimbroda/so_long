# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 12:19:11 by rnuno-im          #+#    #+#              #
#    Updated: 2025/11/25 18:20:39 by rnuno-im         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	so_long

CC			=	cc
CFLAGS		= 	-Werror -Wextra -Wall

# Directorios
PATH_MLX 	= 	srcs/using_mlx/
PATH_MAP 	= 	srcs/map_verification/
MLX_PATH	=	minilibx-linux

# Archivos fuente
MAP_SRCS 	=	map_utils.c map_possible.c map_check_full.c
MLX_SRCS 	=	utils_mlx.c moves_mlx.c using_mlx.c draw_map.c

SRCS = $(addprefix $(PATH_MAP), $(MAP_SRCS)) $(addprefix $(PATH_MLX), $(MLX_SRCS)) srcs/main.c

# Bibliotecas
LIBS		=	srcs/libs/libft/libft.a srcs/libs/gnl/gnl.a

# Objetos
OBJS		= 	$(SRCS:.c=.o)

# MiniLibX
MLX			=	$(MLX_PATH)/libmlx.a
MLX_FLAGS	= 	-L$(MLX_PATH) -lmlx -lXext -lX11 -lm

# Includes
INCLUDES	=	-I includes -I srcs/libs/libft -I srcs/libs/gnl -I $(MLX_PATH)

RM			= 	rm -rf

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	@make -C srcs/libs/libft
	@make -C srcs/libs/gnl
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Compilation complete: $(NAME)"

$(MLX):
	@make -C $(MLX_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C srcs/libs/libft
	@make clean -C srcs/libs/gnl
	@make clean -C $(MLX_PATH)
	$(RM) $(OBJS)
	@echo "🧹 Object files cleaned."

fclean: clean
	@make fclean -C srcs/libs/libft
	@make fclean -C srcs/libs/gnl
	$(RM) $(NAME)
	@echo "🗑️  All cleaned (including binary)."

re: fclean all

.PHONY: all clean fclean re