# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 20:40:02 by obelaizi          #+#    #+#              #
#    Updated: 2023/02/17 21:23:21 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
FLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard ./Mondatory/*.c ./gnl/*.c)
OBJS= $(SRCS:.c=.o)

SRCS_BONUS = $(wildcard ./Bonus/*.c ./gnl/*.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : libft.a $(NAME)

%_bonus.o: %_bonus.c ./Bonus/so_long_bonus.h ./gnl/get_next_line.h
	cc -c $(FLAGS) -Imlx -c $< -o $@

%.o: %.c ./Mondatory/so_long.h ./gnl/get_next_line.h
	cc -c $(FLAGS) -Imlx -c $< -o $@
	

libft.a :
	@make -C Libft all bonus

$(NAME_BONUS): $(OBJS_BONUS)
	cc $(OBJS_BONUS) ./Libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	
$(NAME): $(OBJS)
	cc $(OBJS) ./Libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: libft.a $(NAME_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean:clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C Libft fclean

re: fclean all