# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 18:57:52 by mpoplow           #+#    #+#              #
#    Updated: 2025/02/21 16:21:59 by mpoplow          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME	:= client
SNAME	:= server

CFLAGS	:= -Wall -Wextra -Werror -MMD -MP
# -fsanitize=address -g

CC := cc

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	FILES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

CFILES	:= $(addprefix src/, \
		client.c server.c )

OFILES	= $(addprefix src/O_D_FILES/, $(notdir $(CFILES:.c=.o)))
DFILES	= $(addprefix src/O_D_FILES/, $(notdir $(CFILES:.c=.d)))

# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#
# 	RULES																		#
# *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*	#

all: $(CNAME) $(SNAME)

$(CNAME): $(OFILES) $(DFILES)
	@make all -sC libft
	@$(CC) src/O_D_FILES/client.o libft/libft.a -o $(CNAME)
	@echo "\033[1;32mCREATE PROGRAM: client\033[0m"

$(SNAME): $(OFILES) $(DFILES)
	@make all -sC libft
	@$(CC) src/O_D_FILES/server.o libft/libft.a -o $(SNAME)
	@echo "\033[1;32mCREATE PROGRAM: server\033[0m"

src/O_D_FILES/%.o: src/%.c | src/O_D_FILES
	@$(CC) $(CFLAGS) -c $< -o $@

src/O_D_FILES:
	@mkdir -p $@

clean:
	@echo "\033[1;33mCLEAN minitalk\033[0m"
	@make fclean -C libft
	@rm -f $(OFILES) $(DFILES)
	@rm -rf src/O_D_Files

fclean: clean
	@echo "\033[1;33mREMOVE PROGRAM: client\033[0m"
	@echo "\033[1;33mREMOVE PROGRAM: server\033[0m"
	@rm -f $(CNAME)
	@rm -f $(SNAME)

re: clean all

prep: fclean all
	@make clean

.SILENT:  $(OFILES) $(DFILES)
.PHONY: all clean fclean re prep