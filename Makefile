# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artprevo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 18:16:55 by artprevo          #+#    #+#              #
#    Updated: 2019/09/19 18:24:52 by artprevo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = artprevo.filler
FLAGS = -Wall -Wextra -Werror
SRC = *.c

all: $(NAME)

$(NAME): libft.a $(SRC)
	@printf "\033[0;36m> Compiling filler\033[0m"
	@gcc $(FLAGS) -I includes/ -L. -lft $(SRC) -o $(NAME)
	@printf "\033[0;32m OK\n\033[0m"

libft.a:
	@make -C libft/
	@mv libft/libft.a .
	@make clean -C libft/

test: $(NAME)
	@printf "\033[0;31m- Executing filler -\n\033[0m"
	@cp filler players/
	@./filler_vm -f maps/map01 -p1 players/filler
	@printf "\033[0;31m-- End of filler --\n\033[0m"

test_map: $(NAME)
	@printf "\033[0;31m- Executing filler -\n\033[0m"
	@cp artprevo.filler players/
	@./filler_vm -f maps/$(ARGS) -p1 players/artprevo.filler -p2 players/superjeannot.filler
	@printf "\033[0;31m-- End of filler --\n\033[0m"

clean:
	@rm -f libft.a

fclean: clean
	@rm -f $(NAME)

re: fclean all
