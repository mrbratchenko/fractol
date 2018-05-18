# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbratche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 14:45:53 by sbratche          #+#    #+#              #
#    Updated: 2017/10/29 14:46:17 by sbratche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC_DIR =	./src/
OBJ_DIR =	./obj/
INC_DIR =	./inc/

SRC		=	ft_memcmp.c ft_striteri.c ft_memcpy.c ft_strjoin.c ft_memdel.c \
		ft_strlcat.c ft_atoi.c ft_memmove.c ft_strlen.c ft_binary_search.c \
		ft_memset.c ft_strmap.c ft_bubble_sort.c ft_putchar.c ft_strmapi.c \
		ft_bzero.c ft_putchar_fd.c ft_strncat.c ft_isalnum.c ft_putendl.c \
		ft_strncmp.c ft_isalpha.c ft_putendl_fd.c ft_strncpy.c ft_isascii.c \
		ft_putnbr.c ft_strnequ.c ft_isdigit.c ft_putnbr_fd.c ft_strnew.c \
		ft_isprint.c ft_putstr.c ft_strnstr.c ft_itoa.c ft_putstr_fd.c \
		ft_strrchr.c ft_lstadd.c ft_strcat.c ft_strsplit.c ft_lstdel.c \
		ft_strchr.c ft_strstr.c ft_lstdelone.c ft_strclr.c ft_strsub.c \
		ft_lstiter.c ft_strcmp.c ft_strtrim.c ft_lstmap.c ft_strcpy.c \
		ft_tolower.c ft_lstnew.c ft_strdel.c ft_toupper.c ft_memalloc.c \
		ft_strdup.c ft_memccpy.c ft_strequ.c ft_memchr.c ft_striter.c \
		get_next_line.c


OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

PRINT	=	@echo "\033[32m-\033[0m\c"

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\033[32m> Libft built. \033[0m\c" && ar rc $(NAME) $(OBJ)
		@echo && ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		@echo '\c' && mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		$(PRINT) && gcc -Wall -Werror -Wextra -c $< -o $@ -I $(INC_DIR)

clean:
		@echo '\c' && rm -f $(OBJ)

fclean: clean
		@echo '\c' && rm -f $(NAME)
		@echo '\c' && rm -rf $(OBJ_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
