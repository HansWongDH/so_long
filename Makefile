# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 18:02:33 by wding-ha          #+#    #+#              #
#    Updated: 2022/03/31 19:51:12 by wding-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= test
#############################################################
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -g3
RM				= rm -f
#############################################################
INC				= -Iinclude -I$(LIBFT_DIR)
LIBFT_DIR		= libs/libft
LIB				= -L$(LIBFT_DIR) -lft
SRC_DIR			= src/
MAIN			= $(SRC_DIR)main.c
S_SRCS			= $(SRC_DIR)parse_map.c $(SRC_DIR)initialize_map.c $(SRC_DIR)game_init.c $(SRC_DIR)player_movement.c $(SRC_DIR)map_check.c
OBJS			= $(S_SRCS:.c=.o)
LIBX			= -lmlx -framework OpenGL -framework AppKit

all:			$(NAME) $(C_NAME)

$(NAME):		$(OBJS) $(MAIN)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INC) $(LIBX) -o $(NAME) $(MAIN) $(OBJS) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re