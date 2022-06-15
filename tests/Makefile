NAME = minishell

CFLAGS = -Wall -Wextra -Werror

RL_INC	= -I/goinfre/$(USER)/.brew/opt/readline/include

RL_LIB = -L/goinfre/$(USER)/.brew/opt/readline/lib

SRC = exec.c \
	signal.c \
	builtins/ft_echo.c \
	builtins/ft_pwd.c \
	builtins/ft_env.c \
	builtins/ft_minishell.c \
	utils/ft_split.c \
	utils/ft_str.c \
	minishell.c

OBJ = $(SRC:.c=.o)

%.o : %.c
	@$(CC) $(RL_INC) -I $(RL_INC) -o $@  -c $^

$(NAME) : $(OBJ) minishell.h 
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -l readline $(RL_LIB)

all : $(NAME)

readline :
	brew update && brew install readline && brew upgrade readline

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
