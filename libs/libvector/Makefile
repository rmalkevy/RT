# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/27 15:21:54 by kandreyc          #+#    #+#              #
#    Updated: 2017/05/31 16:18:45 by mrassokh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libvector.a

HEAD_FILE	=	vector_lib.h

GREEN		=	\033[32m
RESET		=	\033[39m
YELLOW		=	\033[33m
RED			=	\033[31m

PATH		=	./functions

SRC_C		=	$(PATH)/vector_cos.c			\
				$(PATH)/vector_mod.c 			\
				$(PATH)/vector_set.c			\
				$(PATH)/vector_sum.c			\
				$(PATH)/vector_mult.c			\
				$(PATH)/vector_unit.c			\
				$(PATH)/vector_dot.c			\
				$(PATH)/vector_cross.c		\
				$(PATH)/vector_sub.c		\
				$(PATH)/intersection_point.c \
				$(PATH)/vector_mult2.c

SRC_O		=	$(SRC_C:.c=.o)


all: $(NAME)

$(NAME): $(SRC_O)
	@ ar rc $(NAME) $(SRC_O)
	@ ranlib $(NAME)
	@ echo "$(GREEN)[vector_lib]$(RESET)"

%.o: %.c
	@ gcc -c -Wall -Wextra -Werror -o $@ $< -I ./includes
	@ printf ' $(GREEN)[add]$(RESET) $<\n'

clean:
	@ /bin/rm  -f  $(SRC_O)
	@ echo "$(YELLOW)[vector_lib] [clean]$(RESET)"

fclean: clean
	@ /bin/rm  -f  $(NAME)
	@ echo "$(RED)[vector_lib] [fclean]$(RESET)"

re: fclean all
