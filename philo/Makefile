# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 15:20:31 by seunghoy          #+#    #+#              #
#    Updated: 2023/06/05 16:19:34 by seunghoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
CC := cc
CFLAGS := -Werror -Wall -Wextra
DEBUG_FLAGS := -g #-fsanitize=thread
SRCS_DIR := srcs
OBJS_DIR := objs

CHANGABLE_HEADERS = philo.h structure.h consts.h

SRCS := $(addprefix $(SRCS_DIR)/, main.c err.c utils.c init.c free_destroy.c \
child_thread.c child_thread_utils.c time_sleep.c )

OBJS := $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

$(NAME) : $(OBJS) $(CHANGABLE_HEADERS)
	$(CC) $(CFLAGS) -I. $(OBJS) $(DEBUG_FLAGS) -o $(NAME)

all : $(NAME)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I. -c $< $(DEBUG_FLAGS) -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re
