
NAME = push_swap
LIBFT_NAME = libft.a
SRCS = ./src/push_swap.c \
		./src/ordenation.c \
		./src/pilea_operations.c \
		./src/pileb_operations.c \
		./src/piles_operations.c \
		./src/ordenation_utils.c \
		./src/push_swap_utils.c \
		./src/list_utils.c \
		./src/format.c

OBJS = ${SRCS:.c=.o}
LIBFT_DIR = ./libft/
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -o $@
$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
	$(CC) -o $(NAME)  $^
$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

debug: $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
	$(CC) -g $(SRCS) $(LIBFT_DIR)$(LIBFT_NAME) -o puchi_debug

re: clean all

.PHONY: all clean fclean re