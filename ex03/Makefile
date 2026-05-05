# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 16:12:37 by pcervill          #+#    #+#              #
#    Updated: 2026/02/10 12:53:24 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	Bureaucrat
SRCS = 	Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp main.cpp Intern.cpp

CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address -I/usr/local/opt/readline/include

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:	
		@$(RM) $(OBJS)


fclean:	clean
		@$(RM) $(NAME)

re:	fclean all
			
.PHONY: all clean fclean re