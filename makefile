NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c \
       list.c \
       swap.c \
       push.c \
       rotate.c \
       rev_rot.c \
       algorithm.c \
       algo_utils.c \
       algo_utils2.c \
       algo_utils3.c \
       allocation.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) includes/libft/libft.a
	$(CC) $(FLAGS) $(OBJS) includes/libft/libft.a -o $(NAME)

includes/libft/libft.a:
	@cd includes/libft && make

re: fclean all

clean:
	@cd includes/libft && make clean
	$(RM) $(OBJS)

fclean:
	@cd includes/libft && make fclean
	$(RM) $(NAME) $(OBJS)

.PHONY: all clean fclean re
