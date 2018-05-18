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

NAME	=	fractol

GCC		=	gcc -Wall -Wextra -Werror

SRC		= ./src/main.c ./src/fractals.c ./src/fractals1.c ./src/key_hooks.c ./src/strings.c \
		./src/init.c ./src/mouse_hooks.c

OBJ 	=	$(addprefix $(), $(SRC:.c=.o))

INC		=	./inc/fractal.h

all: $(NAME)

$(NAME): $(OBJ)
	@echo && make re -C ./libft
	@echo && make re -C ./libft/ft_printf
	@echo "\033[32m-> Fractal built. \033[0m" && $(GCC) $(SRC) -I $(INC) -I /usr/local/include ./libft/libft.a ./libft/ft_printf/libftprintf.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	@echo '\c' && $(GCC) -c $< -o $@  -I $(INC)

clean:
	rm -f $(OBJ)
	@echo '\c' && make clean -C ./libft
	@echo '\c' && make clean -C ./libft/ft_printf

fclean: clean
	rm -f $(NAME)
	@echo '\c' && make fclean -C ./libft
	@echo '\c' && make fclean -C ./libft/ft_printf

re: fclean all
