# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcharbon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 16:18:38 by vcharbon          #+#    #+#              #
#    Updated: 2016/11/27 14:38:49 by vcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
C_FILES = main.c algo.c function1.c function2.c function3.c backtrack.c

O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME):
		gcc -c -Wall -Werror -Wextra $(C_FILES)
		gcc -o $(NAME) $(O_FILES)

clean:
		/bin/rm -f $(O_FILES)

fclean: clean
		/bin/rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
