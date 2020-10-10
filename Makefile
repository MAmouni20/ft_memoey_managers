# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmostafa <mmostafa@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 01:53:49 by mmostafa          #+#    #+#              #
#    Updated: 2020/10/10 15:06:16 by mmostafa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR = libft_malloc_$$HOSTTYPE
LIB_NAME = $(LIB_DIR)/$(LIB_DIR).so
LIB_LINK = libft_malloc.so

SRC = ft_large.c ft_malloc.c ft_small.c ft_tiny.c ft_tools.c
OBJ = obj/ft_large.o obj/ft_malloc.o obj/ft_small.o obj/ft_tiny.o obj/ft_tools.o 

SRCDIR = ./src/
INC = ./inc/
OBJDIR = ./obj/

FLAGS = -Wall -Wextra -Werror

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	@mkdir -p $(LIB_DIR)
	gcc $(FLAGS) -shared $(OBJ) -o $@

$(OBJDIR)%.o: $(SRCDIR)%.c $(INC)memory_managers.h
	@mkdir -p $(OBJDIR)
	gcc $(FLAGS) -I $(INC) -c $< -o $@
	@/bin/ln -sf $(LIB_NAME) $(LIB_LINK)

clean:
	rm -fr $(LIB_DIR)
	rm -f $(LIB_LINK)

fclean:
	make clean
	rm -fr $(OBJ)
re:
	make fclean
	make all
