# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <yli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 15:25:00 by yli               #+#    #+#              #
#    Updated: 2023/02/12 21:16:17 by yli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CFLAGS = -Wall -Werror -Wextra
MINILIBX_FLAGS = -Lmlx_linux -lmlx_Linux -L/user/lib -Imlx_linux -lXext -lX11 -lm -lz

GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

CC = cc
VALGRIND = @valgrind --leak-check=full

SRCS_DIR = ./mandatory/
SRCS_BONUS_DIR = ./bonus/

SRCS = $(addprefix $(SRCS_DIR), ft_utils.c ft_map_check.c ft_map_init.c ft_game_init.c \
	ft_game_input.c ft_game_run.c ft_game_close.c so_long.c)
SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR), ft_utils_bonus.c ft_map_check_bonus.c \
	ft_map_init_bonus.c ft_game_init_bonus.c ft_game_input_bonus.c \
	ft_game_run_bonus.c ft_game_close_bonus.c so_long_bonus.c)
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBGNL = LIBGNL/libgnl.a

all: $(NAME) $(LIBGNL)

$(NAME): $(OBJS)
	@echo "$(GREEN)\nmaking libft...ft_printf...GNL...$(RESET)"
	@make -C LIBGNL
	@cp $(LIBGNL) $(NAME)
	$(CC) $(SRCS) $(LIBGNL) $(MINILIBX_FLAGS) $(CFLAGS) -o $(NAME) 
	#ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)\nmandatory norminette$(RESET)"
	@norminette $(SRCS)

bonus: $(NAME_BONUS) $(LIBGNL)

$(NAME_BONUS):  $(OBJS_BONUS)
	@echo "$(GREEN)\nmaking libft...ft_printf...GNL...$(RESET)"
	@make -C LIBGNL
	@cp $(LIBGNL) $(NAME_BONUS)
	$(CC) $(SRCS_BONUS) $(LIBGNL) $(MINILIBX_FLAGS) $(CFLAGS) -o $(NAME_BONUS) 
	@echo "$(GREEN)\nbonus norminette$(RESET)"
	@norminette $(SRCS_BONUS)

clean: 
	rm -f $(OBJS) $(OBJS_BONUS)
	@echo "$(BLUE)\ncleaning libft...ft_printf...GNL...$(RESET)"
	@make clean -C LIBGNL
	
fclean: clean
	@echo "$(BLUE)\nfcleaning libft...ft_printf...GNL...$(RESET)"
	@make fclean -C LIBGNL
	rm -f $(NAME) $(NAME_BONUS)

re: fclean
	make all

rebonus: fclean
		make bonus
run: $(NAME) 
	$(VALGRIND) ./$(NAME) assets/map/map1.ber
	
runbonus: $(NAME_BONUS) 
	$(VALGRIND) ./$(NAME_BONUS) assets/map/map6.ber

PHONY: all clean fclean re run rebonus runbonus bonus
