# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 17:10:27 by rnaumenk          #+#    #+#              #
#    Updated: 2018/03/01 17:10:28 by rnaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	rnaumenk.filler
LIBFT_DIR	=	./libft/
LIBFT		=	libft.a
LIB			=	libftfiller.a
INC_DIR		=	./include/
INC			=	filler.h
SRC_DIR		=	./src/
SRC			= 	answer_searcher.c \
				distance_drawer.c \
				first_scan.c \
				free.c \
				main.c \
				map_and_figure_creation.c \
				token_mover.c
OBJ_DIR		=	./obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT_DIR)$(LIBFT) $(LIB)
	@gcc -Wall -Wextra -Werror -o $@ $^
	@echo "\033[4;32mrnaumenk.filler is ready\033[0m"

$(LIB): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[3;36mlibftfiller.a has been made\033[0m"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC_DIR)$(INC)
	@mkdir -p $(OBJ_DIR)
	@gcc -Wall -Wextra -Werror -o $@ -c $<

$(LIBFT_DIR)$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "\033[3;36mlibft.a has been made\033[0m"

clean:
	@rm -rf $(LIB) $(OBJ_DIR)
	@cd $(LIBFT_DIR) && make fclean
	@echo "\033[3;33mlibft.a and libftfiller.a have been deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[3;31mrnaumenk.filler has been deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re
