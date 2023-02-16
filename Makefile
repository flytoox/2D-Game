# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 20:40:02 by obelaizi          #+#    #+#              #
#    Updated: 2023/02/16 23:59:19 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
FLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard ./Mondatory/*.c ./gnl/*.c)
OBJS= $(SRCS:.c=.o)

SRCS_BONUS = $(wildcard ./Bonus/*.c ./gnl/*.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

%_bonus.o: %_bonus.c ./Bonus/so_long_bonus.h ./gnl/get_next_line.h
	cc -c $(FLAGS) -g -I/usr/include -Imlx_linux -O3 $< -o $@
	

%.o: %.c ./Mondatory/so_long.h ./gnl/get_next_line.h
	cc -c $(FLAGS) -g -I/usr/include -Imlx_linux -O3 $< -o $@
	


libft.a :
	make -C Libft all bonus

$(NAME_BONUS): libft.a $(OBJS_BONUS)
	cc $(OBJS_BONUS) ./Libft/libft.a -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	
$(NAME): libft.a $(OBJS)
	cc $(OBJS) ./Libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean:clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C Libft fclean

re: fclean all
