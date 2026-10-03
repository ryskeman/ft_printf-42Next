NAME        = libftprintf.a
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)

AR          = ar rcs
RM          = rm -f

COMMON_SRCS = ft_printf.c \
              print_args.c \
              print_chars.c \
              print_numbers.c \
              print_hex.c \
              print_ptr.c

MAND_SRCS   = $(COMMON_SRCS) parser.c
BONUS_SRCS  = $(COMMON_SRCS) parser_bonus.c

MAND_OBJS   = $(MAND_SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MAND_OBJS)
	@rm -f .bonus
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(MAND_OBJS)
	@echo "$(NAME) (Mandatory) creado con éxito."

bonus: .bonus

.bonus: $(LIBFT) $(BONUS_OBJS)
	@rm -f $(NAME)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)
	@touch .bonus
	@echo "$(NAME) (Bonus) creado con éxito."

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(MAND_OBJS) $(BONUS_OBJS) .bonus
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Objetos eliminados."

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Librerías y binarios eliminados."

re: fclean all

.PHONY: all clean fclean re bonus