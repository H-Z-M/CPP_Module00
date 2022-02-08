NAME		= megaphone
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror
SRCS_DIR	= ./
SRCS		= megaphone.cpp
OBJS_DIR	= objs/
OBJ			= $(SRCS:.cpp=.o)
OBJS		= $(addprefix $(OBJS_DIR), $(OBJ))
RM			= rm -rf

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

re : fclean all

test : $(NAME)
	@./$(NAME) "shhhhh... I think the students are asleep..."
	@./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@./$(NAME)

.PHONY: all clean fclean re test
