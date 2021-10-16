# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 15:10:45 by ldavids           #+#    #+#              #
#    Updated: 2021/04/27 14:41:40 by ldavids          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C checker_src
	@cp ./checker_src/checker .
	make sub -C push_swap_src
	@cp ./push_swap_src/push_swap .

push_swap:
	make -C push_swap_src
	@cp ./push_swap_src/push_swap .

checker:
	make -C checker_src
	@cp ./checker_src/checker .

clean:
	make -C checker_src clean
	make -C push_swap_src clean

fclean:
	make -C checker_src fclean
	make -C push_swap_src fclean
	rm -rf checker push_swap

re: fclean all

.PHONY: all clean fclean re checker push_swap
