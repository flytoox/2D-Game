# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 20:40:02 by obelaizi          #+#    #+#              #
#    Updated: 2023/01/26 21:50:28 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c ./gnl/*.c)
OBJS= $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c push_swap.h ./gnl/get_next_line.h 
	cc -c $(FLAGS) $<

libft.a : 
	make -C Libft

$(NAME): libft.a $(OBJS)
	@cc $(OBJS) ./Libft/libft.a -o $(NAME)

bonus: $(OBJS_BONUS)
	@cc $(OBJS_BONUS) -o $(NAME_BONUS)

clean: 
	@rm -f $(OBJS) $(OBJS_BONUS) 

fclean:clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C Libft fclean

re: fclean all