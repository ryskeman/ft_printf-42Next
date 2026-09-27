# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/23 14:20:10 by fernfern          #+#    #+#              #
#    Updated: 2026/09/25 10:57:13 by fernfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FILE NAME
NAME = libft.a

# COMPILATOR
CC = cc

# COMPILATION FLAGS
CFLAGS = -Wall -Wextra -Werror


# ARCHIVER
AR = ar rcs

# INCLUDES
INCLUDES = libft.h

# SOURCES FILES
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

# OBJECTS LIST CREATOR
OBJS = $(SRCS:.c=.o)

# LIBRARY RULE CREATOR
$(NAME): $(OBJS)
		$(AR) $@ $^

# MAIN RULE: LIBFT.A CREATOR
all: $(NAME)

# CREATOR OBJECTS RULE
%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

# CLEAN RULE: DELETE OBJECT FILES
clean:
	rm -f $(OBJS)

# FCLEAN RULE: DELETE OBJECTS AND LIBRARY
fclean: clean
	rm -f $(NAME)

# RE RULE: RECOMPILES ALL
re: fclean all

# PHONY TARGETS
.PHONY: all clean fclean re