# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/20 18:10:37 by otidahoh          #+#    #+#              #
#    Updated: 2026/07/20 18:10:55 by otidahoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Contact.cpp PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
