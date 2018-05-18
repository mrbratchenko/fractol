# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbratche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/03 19:51:53 by sbratche          #+#    #+#              #
#    Updated: 2018/02/03 19:51:55 by sbratche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC_DIR =	./src/
OBJ_DIR =	./obj/
INC_DIR =	./inc/

SRC		= ft_actual_printf.c ft_process_nbrs.c ft_printf.c ft_atoi.c \
		ft_isdigit.c ft_putchar.c ft_strlen.c ft_strjoin.c ft_strcat.c \
		ft_strcpy.c ft_strsub.c ft_process_str.c ft_itoa_base_unsigned.c \
		ft_strnew.c ft_process_char.c ft_memset.c ft_itoa_base_signed.c \
		ft_get_specs.c ft_strdup.c ft_isalpha.c ft_strcmp.c ft_process_d_i.c \
		ft_process_percent.c ft_process_w_char.c ft_process_w_str.c \
		ft_process_unsigned.c ft_process_hex.c ft_process_oct.c \
		ft_process_address.c ft_process_invalid.c ft_print_str.c \
		ft_print_char.c ft_calc_w_len.c \

OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

PRINT	=	@echo "\033[32m-\033[0m\c"

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\033[32m> Printf built. \033[0m\c" && ar rc $(NAME) $(OBJ)
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
