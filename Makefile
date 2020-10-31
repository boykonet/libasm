# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkarina <gkarina@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 00:03:53 by gkarina           #+#    #+#              #
#    Updated: 2020/10/31 00:03:53 by gkarina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

ASMSRCS =	./libasm/ft_strlen.s \
			./libasm/ft_strcpy.s \
			./libasm/ft_strcmp.s \
			./libasm/ft_write.s \
			./libasm/ft_read.s \
			./libasm/ft_strdup.s

ASMOBJS = $(ASMSRCS:%.s=%.o)

INCLUDES = ./libasm/libasm.h

all: $(NAME)

$(NAME): $(ASMOBJS) $(INCLUDES)
	ar rc $@ $(ASMOBJS)
	ranlib $@

%.o: %.s
	nasm -fmacho64 $<

clean:
	rm -rf $(ASMOBJS)

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all, clean, fclean, re
