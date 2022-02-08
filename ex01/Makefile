NAME		= phonebook
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror
SRCS_DIR	= ./
SRCS		= main.cpp phonebook.cpp contact.cpp
OBJS_DIR 	= objs/
OBJ			= $(SRCS:.cpp=.o)
OBJS		= $(addprefix $(OBJS_DIR), $(OBJ))
INCLUDES	= ./includes
RM			= rm -rf
CXXFLAGS	+= -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

test : $(NAME)
	@./$(NAME)

re : fclean all

.PHONY: all clean fclean re test
