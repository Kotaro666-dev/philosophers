# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 08:28:31 by kkamashi          #+#    #+#              #
#    Updated: 2022/04/27 09:31:02 by kkamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror
PTHREAD = -pthread
DEBUG = -g -fsanitize=address
DEPENDENCY_OPTION = -MMD -MP -MF
SRCS_DIR = ./srcs

SRCS =	main.c

SRCS += ${shell find ./srcs -type f -name "*.c"}

INCLUDE =	-I./includes/ \

OBJS = $(SRCS:.c=.o)
DEPS = ${SRCS:.c=.d}

.c.o:
	$(CC) $(CFLAGS) ${PTHREAD} $(DEBUG) $(INCLUDE) -c $(DEPENDENCY_OPTION) ${<:.c=.d} \
	$< -o ${<:.c=.o}

$(NAME): $(OBJS)
	${CC} ${CFLAGS} ${PTHREAD} $(DEBUG) ${OBJS} -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(DEPS) $(BONUS_DEPS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
