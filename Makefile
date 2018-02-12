# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 17:01:42 by jmeier            #+#    #+#              #
#    Updated: 2018/02/10 14:49:24 by jmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FUNC = main parse draw color

C_LOC = src/
C_NAM = $(addsuffix .c, $(FUNC))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FUNC))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

LIB_LOC = ftprintf/
LIB_NAM = libftprintf.a
LIB_SRC = $(addprefix $(LIB_LOC), $(LIB_NAM))

MLX = mlx/libmlx.a

MLX_FLAGS = -L mlx -lmlx -framework OpenGL -framework Appkit -g

H_LOC = -I inc/ -I ftprintf/inc -I ftprintf/libft/inc -I mlx/
HEADERS = inc/*.h

all: $(NAME)

$(NAME): $(MLX) $(LIB_SRC) $(O_SRC)
	@/bin/echo -n "無駄"
	@gcc -Wall -Werror -Wextra $(MLX_FLAGS) -lpthread $^ -o $(NAME)
	@/bin/echo -n "ァァ！」"
	@echo "\nそして、時は動き出す。"

$(O_LOC)%.o: $(C_LOC)%.c $(HEADERS)
	@/bin/echo -n "無駄"
	@gcc -Wall -Werror -Wextra $(H_LOC) -o $@ -c $<
	@/bin/echo -n "無駄"

$(LIB_SRC): force
	@make -C $(LIB_LOC)
	@echo
	@/bin/echo -n "「無駄だ！無駄"

$(MLX): force
	@make -C mlx

force:
	@true

clean:
	@echo "ザ・ワールド！"
	@/bin/rm -f $(O_SRC)
	@make clean -C mlx

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_LOC)
	@echo "時よ止まれ！"

re: fclean all

.PHONY: all clean fclean re
