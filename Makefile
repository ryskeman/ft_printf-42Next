NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)
AR = ar rcs
RM = rm -f


#SOURCES
SRCS =	ft_printf.c \
		print_args.c \
		print_chars.c \
		

OBJS = $(SRCS:.c=.o)


#RULES
all: $(NAME)


$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@echo "$(NAME) creado con éxito."

$(LIBFT): make_libft


make_libft:
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@


#BONUS RULE
bonus: all

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Objetos eliminados."


fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Librerías y binarios eliminados."


re: fclean all

.PHONY: all clean fclean re bonus make_libft