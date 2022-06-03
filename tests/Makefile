NAME = minishell

CFLAGS = -Wall -Wextra -Werror

RL_INC	= -I/goinfre/$(USER)/.brew/opt/readline/include

RL_LIB = -L/goinfre/$(USER)/.brew/opt/readline/lib

SRC = gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	readline.c

OBJ = $(SRC:.c=.o)

%.o : %.c
	@$(CC) $(RL_INC) -I $(RL_INC) -o $@  -c $^

all : $(NAME)

$(NAME) : $(OBJ) test.h 
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -l readline $(RL_LIB)

readline :
	brew install readline && brew update && brew upgrade readline

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
