# Makefile for ex00 (BraiiiiiiinnnzzzZ)
# Custom variable names for personal touch

PROJECT_NAME	= brainz
CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
RM				= rm -f

# Header directory if needed (here we are in the same directory):
INCLUDES		= Zombie.hpp

# All source files:
SRC_FILES		= main.cpp \
				  Zombie.cpp \
				  newZombie.cpp \
				  randomChump.cpp

# Object files (auto conversion from .cpp to .o):
OBJ_FILES		= $(SRC_FILES:.cpp=.o)

# Default Rule:
all: $(PROJECT_NAME)

# Linking:
$(PROJECT_NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(PROJECT_NAME) $(OBJ_FILES)
	@echo "\n🧟 Build Successful! Output binary: $(PROJECT_NAME)\n"

# Compiling objects:
%.o: %.cpp $(INCLUDES)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleaning rules:
clean:
	@$(RM) $(OBJ_FILES)
	@echo "🧹 Objects cleared."

fclean: clean
	@$(RM) $(PROJECT_NAME)
	@echo "🔥 Binary cleared."

re: fclean all

# Don't mistake these for actual files:
.PHONY: all clean fclean re
