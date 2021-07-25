# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 20:40:15 by joeduard          #+#    #+#              #
#    Updated: 2021/07/25 20:40:15 by joeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_utils.c ft_printf_utils_2.c ft_printf_utils_3.c ft_printf.c print_c.c print_id.c \
	   print_p.c print_s.c print_u.c print_xX.c

OBJECTS = $(subst .c,.o,$(SRCS))

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS) 

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
