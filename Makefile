# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 16:01:21 by mannahri          #+#    #+#              #
#    Updated: 2023/01/01 08:15:53 by mannahri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src = main.c ./parsing/get_next_line.c ./parsing/get_next_line_utils.c\
./parsing/read_check_map.c ./parsing/read_check_map0.c ./parsing/read_check_map1.c \
./parsing/read_check_map2.c ./parsing/read_check_map3.c ./parsing/read_check_map4.c\
./parsing/parsing.c ./libft/*.c 
cub3d = cub3d
SANITIZE = -g -fsanitize=address
FLAGS = -Wall -Wextra -Werror
CC = cc

all : cub3d
$(cub3d): $(src)
	@$(CC) $(FLAGS) $(src) $(SANITIZE) -o cub3d
	@tput setaf 2; echo "cub3d IS READY"

clean :
	@rm -f *.o
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean
	@rm -f cub3d
	@tput setaf 1; echo "FCLEAN COMPLET"
re: fclean all