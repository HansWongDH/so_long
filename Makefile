# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 18:02:33 by wding-ha          #+#    #+#              #
#    Updated: 2022/03/29 14:22:45 by wding-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= test
#############################################################
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
#############################################################
INC				= -Iinclude -I$(LIBFT_DIR)
LIBFT_DIR		= libs/libft
LIB				= -L$(LIBFT_DIR) -lft
SRC_DIR			= src/
S_SRCS			= $(SRC_DIR)parse_map.c
OBJS			= $(S_SRCS:.c=.o)

all:			$(NAME) $(C_NAME)

$(NAME):		$(OBJS)
	make re -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -lmlx -framework OpenGL -framework Appkit -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean

.PHONY: all clean fclean re