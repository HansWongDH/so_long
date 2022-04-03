# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 18:02:33 by wding-ha          #+#    #+#              #
#    Updated: 2022/04/03 18:20:58 by wding-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
#############################################################
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
#############################################################
INC				= -Iinclude -I$(LIBFT_DIR)
LIBFT_DIR		= libs/libft
LIB				= -L$(LIBFT_DIR) -lft
SRC_DIR			= src/
MAIN			= $(SRC_DIR)main.c
S_SRCS			= $(SRC_DIR)parse_map.c $(SRC_DIR)initialize_map.c $(SRC_DIR)game_init.c $(SRC_DIR)player_movement.c $(SRC_DIR)map_check.c\
					$(SRC_DIR)map_getinfo.c $(SRC_DIR)error_handling.c
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