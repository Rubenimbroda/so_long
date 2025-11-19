# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 12:19:11 by rnuno-im          #+#    #+#              #
#    Updated: 2025/11/19 10:53:28 by rnuno-im         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	so_long

CC		=	cc
CFLAGS	= 	-Werror -Wextra -Wall

LIBFT	=	./libft/libft.a

SRCS	=	so_long.c 

OBJS	= 	$(SRCS:.c=.o)

MLX		= 	-lmlx -framework OpenGL -framework Appkit

RM		= 	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "✅ Compilation complete: $(NAME)"
	
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
	@echo "🧹 Object files cleaned."

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	@echo "🗑️  All cleaned (including binary)."

re: fclean all

.PHONY: all clean fclean re