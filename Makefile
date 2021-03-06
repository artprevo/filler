# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artprevo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 18:16:55 by artprevo          #+#    #+#              #
#    Updated: 2019/10/29 15:44:13 by artprevo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = artprevo.filler
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRCS += algo.c
SRCS += dominance.c
SRCS += find_distances.c
SRCS += freeall.c
SRCS += gather_result.c
SRCS += init.c
SRCS += main.c
SRCS += origin.c
SRCS += parsing.c
SRCS += parsing_tools.c
SRCS += print.c
SRCS += proxdomi.c
SRCS += result_tools.c
SRCS += utility.c
SRCS += checkerror.c
OBJS_PATH = objs/
SRCS_PATH = srcs/
OBJS = $(patsubst %.c, $(OBJS_PATH)%.o, $(SRCS))
LIBFT = libft/libft.a
HEADER = ./includes/filler.h ./libft/libft.h
INCLUDES = -I ./includes/ -I ./libft/

all: $(LIBFT) $(OBJS_PATH) $(NAME)

$(NAME): $(OBJS)
	printf "\033[0;36m> Compiling filler\033[0m"
	$(CC) $(CFLAGS) $(INCLUDES) -Llibft/ -lft $^ -o $@
	printf "\033[0;32m OK\n\033[0m"

$(OBJS): $(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_PATH):
	mkdir $@

$(LIBFT): FORCE
	$(MAKE) -C libft/

FORCE:

clean:
	$(RM) -R $(OBJS_PATH)
	$(MAKE) -C libft/ clean

fclean: clean
	$(MAKE) -C libft/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: test test_map clean fclean re all
.SILENT:
