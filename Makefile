# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 12:19:11 by rnuno-im          #+#    #+#              #
#    Updated: 2025/11/27 12:41:17 by rubenior         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS_DIR	= src
INCLUDE_DIR	= include
MLX_DIR		= minilibx-linux
LIBFT_DIR	= libft

SRCS	= $(SRCS_DIR)/map_parser.c \
		  $(SRCS_DIR)/render.c \
		  $(SRCS_DIR)/map_utils.c \
		  $(SRCS_DIR)/events.c \
		  $(SRCS_DIR)/validate_map.c \
		  $(SRCS_DIR)/validate_utils.c \
		  so_long.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= $(LIBFT_DIR)/libft.a
MLX		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) -L$(LIBFT_DIR) -lft
	@echo "✅ Compilation complete: $(NAME)"

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	@echo "🧹 Object files cleaned."

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	@echo "🗑️  All cleaned."

re: fclean all

.PHONY: all clean fclean re