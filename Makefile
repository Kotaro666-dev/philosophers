# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 08:28:31 by kkamashi          #+#    #+#              #
#    Updated: 2022/04/10 08:34:39 by kkamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS_NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
DEPENDENCY_OPTION = -MMD -MP -MF
SRCS_DIR = ./srcs

SRCS =	main.c
BONUS_SRCS = main.c

SRCS += ${shell find ./srcs/ -type f -name "*.c"}
BONUS_SRCS += ${shell find ./srcs/ -type f -name "*.c"}

INCLUDE =	-I./includes/ \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
DEPS = ${SRCS:.c=.d}
BONUS_DEPS = ${BONUS_SRCS:.c=.d}

.c.o:
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDE) -c $(DEPENDENCY_OPTION) ${<:.c=.d} \
	$< -o ${<:.c=.o}

$(NAME): $(OBJS)
	${CC} ${CFLAGS} $(DEBUG) ${OBJS} -o $(NAME)

all: $(NAME)

bonus: $(BONUS_OBJS)
	${CC} ${CFLAGS} $(DEBUG) ${BONUS_OBJS} -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(DEPS) $(BONUS_DEPS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS) $(BONUS_DEPS)
