NAME = minishell

CFLAGS = -Wall -Wextra -Werror

SRC = gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	readline.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) test.h 
	@$(CC) $(CFLAGS) $(OBJ) -o $@ -l readline

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all