CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.. -I../libft
NAME_DIR    = ..
LIB         = $(NAME_DIR)/libftprintf.a

TEST_MAND   = test_mandatory.c
TEST_BONUS  = test_bonus_flags.c
TEST_STRICT = test_strict_flags.c

BIN_MAND    = run_mandatory.out
BIN_BONUS   = run_bonus.out
BIN_STRICT  = run_strict.out

RM          = rm -f

all: bonus

# Compila y corre el test mandatory asegurando 'make all' en la raiz
mand: $(LIB_MAND) $(TEST_MAND)
	@$(MAKE) -C $(NAME_DIR) all
	$(CC) $(CFLAGS) $(TEST_MAND) $(LIB) -o $(BIN_MAND)
	@echo "--- EJECUTANDO MANDATORY ---"
	@./$(BIN_MAND)

# Compila y corre los tests de bonus asegurando 'make bonus' en la raiz
bonus: $(TEST_BONUS)
	@$(MAKE) -C $(NAME_DIR) bonus
	$(CC) $(CFLAGS) $(TEST_BONUS) $(LIB) -o $(BIN_BONUS)
	@echo "--- EJECUTANDO BONUS FLAGS ---"
	@./$(BIN_BONUS)

# Compila y corre los tests estrictos con 'make bonus'
strict: $(TEST_STRICT)
	@$(MAKE) -C $(NAME_DIR) bonus
	$(CC) $(CFLAGS) $(TEST_STRICT) $(LIB) -o $(BIN_STRICT)
	@echo "--- EJECUTANDO STRICT FLAGS ---"
	@./$(BIN_STRICT)

# Valgrind sobre bonus
valgrind: bonus
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BIN_BONUS)

clean:
	$(RM) $(BIN_MAND) $(BIN_BONUS) $(BIN_STRICT)

fclean: clean
	@$(MAKE) -C $(NAME_DIR) fclean

re: clean all

.PHONY: all mand bonus strict valgrind clean fclean re