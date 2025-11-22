NAME = gnl.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCE = get_next_line.c get_next_line_utils.c

OBJ = $(SOURCE:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "-->gnl objects created<--"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "->gnl objects cleaned<-"

fclean: clean
	@rm -f $(NAME)
	@echo "->$(NAME) erased<-"

re: fclean all

.PHONY: all clean fclean re
