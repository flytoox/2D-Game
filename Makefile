# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 20:40:02 by obelaizi          #+#    #+#              #
#    Updated: 2023/01/31 21:06:44 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = 

SRCS = $(wildcard *.c ./gnl/*.c)
OBJS= $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c so_long.h ./gnl/get_next_line.h
	cc -c $(FLAGS) -g -I/usr/include -Imlx_linux -O3 $< -o $@

libft.a :
	make -C Libft all bonus

$(NAME): libft.a $(OBJS)
	cc $(OBJS) ./Libft/libft.a -Lmlx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus: $(OBJS_BONUS)
	@cc $(OBJS_BONUS) -o -g  $(NAME_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean:clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C Libft fclean

re: fclean all
