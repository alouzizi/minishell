NAME = minishell

CFLAGS = -Wall -Wextra -Werror

RL_INC	= -I/goinfre/$(USER)/.brew/opt/readline/include

RL_LIB = -L/goinfre/$(USER)/.brew/opt/readline/lib

SRC = exec.c \
	signal.c \
	builtins/ft_echo.c \
	builtins/ft_pwd.c \
	builtins/ft_env.c \
	main.c

OBJ = $(SRC:.c=.o)
LIBFT = ../libft/libft.a

%.o : %.c
	@$(CC) $(RL_INC) -I $(RL_INC) -o $@  -c $^

$(NAME) : $(OBJ) minishell.h $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -I $(LIBFT) -o $(NAME) -l readline $(RL_LIB)

$(LIBFT) :
	@ make -C ../libft

all : $(NAME)

readline :
	brew update && brew install readline && brew upgrade readline

clean :
	make  clean -C ../libft
	@rm -rf $(OBJ)

fclean : clean
	make fclean -C ../libft
	@rm -rf $(NAME)

re : fclean all
