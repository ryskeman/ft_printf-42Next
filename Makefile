NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)
BONUS_FLAG = .bonus

AR = ar rcs
RM = rm -f


# COMMON SOURCES BOTH PARTS(MANDATORY AND BONUS)
COMMON_SRCS =	ft_printf.c \
		print_args.c \
		print_chars.c 
		
# MADATORY SRC: with parser.c
MANDATORY_SRCS = $(COMMON_SRCS) parser.c

# BONUS: with parser_bonus.c
BONUS_SRCS = $(COMMON_SRCS) parser_bonus.c


OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)


#RULES
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(RM) $(BONUS_FLAG)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@echo "$(NAME) (Mandatory) creado con éxito."


#BONUS RULE
bonus: $(BONUS_FLAG)

$(BONUS_FLAG): $(LIBFT) $(BONUS_OBJS)
	@$(RM) $(NAME)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)
	@touch $(BONUS_FLAG)
	@echo "$(NAME) (Bonus) creado con éxito."


$(LIBFT): make_libft

make_libft:
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(BONUS_FLAG)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Objetos eliminados."


fclean: clean
	$(RM) $(NAME) $(BONUS_FLAG)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Librerías y binarios eliminados."


re: fclean all

.PHONY: all clean fclean re bonus make_libft