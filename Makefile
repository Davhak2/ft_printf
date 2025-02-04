NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

AR = ar rcs
SRCS := formats.c ft_printf.c
OBJS := $(SRCS:.c=.o)
RM = rm -rf

LIBFT = ./libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
							$(MAKE) -C libft bonus 
							mv $(LIBFT) ./$(NAME)
							$(MAKE) -C libft clean
$(NAME): $(OBJS) $(LIBFT)
							$(AR) $(NAME) $(OBJS) 
%.o: %.c ft_printf.h
							$(CC) $(CFLAGS) -c $< -o $@
clean:
							$(RM) $(OBJS)
fclean: clean
							$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
