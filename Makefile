# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:34:23 by vzashev           #+#    #+#              #
#    Updated: 2023/12/12 15:11:01 by vzashev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

OBJS := actions.o checks.o dinner.o escape.o main.o my_atoi.o

FLAGS := -Wall -Werror -Wextra -g -pthread

DEFAULT = \033[0m

GREEN = \033[1;32m

YELLOW = \033[1;33m

RED = \033[1;31m

all: $(NAME)

%.o : %.c
	@cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $(NAME) -fsanitize=address
	@echo "$(GREEN)$(NAME) make: created all the objects files and the executable!$(DEFAULT)"

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)clean: deleted all the objects files!$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)fclean: deleted all the objects files and the executable!$(DEFAULT)"

re: clean fclean all

.PHONY: all clean fclean re
