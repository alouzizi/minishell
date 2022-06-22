NAME = minishell

CFLAGS = -Wall -Wextra -Werror

RL_INC	= -I/goinfre/$(USER)/.brew/opt/readline/include

RL_LIB = -L/goinfre/$(USER)/.brew/opt/readline/lib

SRC = exec.c \
	signal.c \
	quotes_handling.c \
	builtins/ft_echo.c \
	builtins/ft_pwd.c \
	builtins/ft_env.c \
	builtins/ft_export.c \
	builtins/export.c \
	builtins/ft_cd.c \
	builtins/ft_minishell.c \
	builtins/ft_unset.c \
	main.c

OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

%.o : %.c
	@$(CC) $(RL_INC) -I $(RL_INC) -o $@  -c $^

$(NAME) : $(OBJ) $(LIBFT) minishell.h
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -l readline $(RL_LIB)

$(LIBFT) :
	@make -C libft

all : $(NAME)

readline :
	brew install readline

clean :
	@make  clean -C libft
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)

re : fclean all
