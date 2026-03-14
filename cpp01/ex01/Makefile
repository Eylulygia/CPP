NAME		= moar_brainz
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCS		= main.cpp \
			  Zombie.cpp \
			  zombieHorde.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\n🧟 Horde ready to be summoned: $(NAME)\n"

%.o: %.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@echo "Objects removed."

fclean: clean
	$(RM) $(NAME)
	@echo "Binary removed."

re: fclean all

.PHONY: all clean fclean re
