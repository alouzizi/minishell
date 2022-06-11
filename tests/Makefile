NAME = minishell

CFLAGS = -Wall -Wextra -Werror

RL_INC	= -I/goinfre/$(USER)/.brew/opt/readline/include

RL_LIB = -L/goinfre/$(USER)/.brew/opt/readline/lib

SRC = exec.c \
	ft_split.c \
	ft_str.c \
	readline.c

OBJ = $(SRC:.c=.o)

%.o : %.c
	@$(CC) $(RL_INC) -I $(RL_INC) -o $@  -c $^

$(NAME) : $(OBJ) test.h 
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -l readline $(RL_LIB)

all : $(NAME)

readline :
	brew update && brew install readline && brew upgrade readline

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
