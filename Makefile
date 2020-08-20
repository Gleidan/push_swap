# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jconcent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 17:43:41 by jconcent          #+#    #+#              #
#    Updated: 2020/08/20 14:40:04 by jconcent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH:= checker
NAME_PS:= push_swap
FILE_C:= ft_checker
FILE_PS:= ft_push_swap
FILES:= backtrack get_args push_swap_simple rotate sort_data \
		useful_function useful_function_2 ch_rotate

LFTDIR:=./libft

COMPILER:=gcc
SRCPATH:=src/
HPATH:=include/
OBJPATH:=obj/
IFLAGS:= -I $(HPATH) -I $(LFTDIR)/include
CFLAGS:= -Wall -Wextra -Werror $(IFLAGS)

SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
SRC_PS:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_PS)))
SRC_C:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILE_C)))
OBJ:=$(addprefix $(OBJPATH),$(addsuffix .o,$(FILES)))
OBJ_PS:=$(addprefix $(OBJPATH),$(addsuffix .o,$(FILE_PS)))
OBJ_C:=$(addprefix $(OBJPATH),$(addsuffix .o,$(FILE_C)))

BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"

CCHF:=.cache_exists

all: $(NAME_PS) $(NAME_CH)

$(NAME_CH): $(OBJ) $(OBJ_C)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@"
	@$(COMPILER) $(CFLAGS) $(SRC) $(SRCPATH)$(FILE_C).c -L $(LFTDIR) -lft -o $(NAME_CH)
	@echo $(GREEN) " - OK"

$(NAME_PS): $(OBJ) $(OBJ_PS)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@"
	@$(COMPILER) $(CFLAGS) $(SRC) $(SRC_PS) -L $(LFTDIR) -lft  -o $(NAME_PS)
	@echo $(GREEN) " - OK"

$(OBJPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@"
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c: 
	@echo $(RED) "Missing file : $@"

$(CCHF):
	@mkdir $(OBJPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(OBJPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean:
	@rm -f $(NAME_CH)
	@rm -f $(NAME_PS)
	@rm -rf $(NAME_CH).dSYM/
	@rm -rf $(NAME_PS).dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all

norm:
	@echo $(RED)
	@norminette $(SRC) $(SRC_PS) $(SRC_C) $(HPATH) | grep -v Norme -B1 || true
	@cd $(LFTDIR) && $(MAKE) norm

.PHONY: all clean fclean re norm