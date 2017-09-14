# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adalenco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 17:12:17 by adalenco          #+#    #+#              #
#    Updated: 2017/09/14 19:43:38 by adalenco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = $(addprefix $(SRCPATH)/,$(FC))

SRCPATH =	./src

FC =		main.c \
			get_next_line.c \
			trace_map.c \
			ft_rotate.c \
			key_funct.c \
			ft_image.c \
			read_parse.c \
			ft_trace_image.c

FCO =	$(FC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FLAGS2 = -framework OpenGL -framework AppKit

INC = ./includes/
LIBFT = ./libft/

all: $(NAME)

$(NAME): $(SRC)
	@gcc $(FLAGS2) $(FCO) ./libft/libft.a ./minilibx_macos/libmlx.a -o $(NAME)

$(SRC): makelib
	@gcc $(FLAGS)  -c $(SRC) -I $(INC) -I $(LIBFT)

makelib:
	@make -C ./libft
	@make -C ./minilibx_macos/

clean:
	@rm -f $(FCO)
	@make -C ./libft clean
	@make -C ./minilibx_macos clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
