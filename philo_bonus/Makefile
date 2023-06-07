# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 15:20:31 by seunghoy          #+#    #+#              #
#    Updated: 2023/06/07 17:15:15 by seunghoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo_bonus
CC := cc
CFLAGS := -Werror -Wall -Wextra
DEBUG_FLAGS := -g #-fsanitize=thread
SRCS_DIR := srcs
OBJS_DIR := objs

CHANGABLE_HEADERS = philo_bonus.h structure_bonus.h consts_bonus.h

SRCS := $(addprefix $(SRCS_DIR)/, main_bonus.c err_bonus.c utils_bonus.c \
init_bonus.c free_bonus.c child_bonus.c parent_bonus.c monitor_bonus.c \
time_sleep_bonus.c)

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
