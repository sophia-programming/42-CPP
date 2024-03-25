NAME = Bureaucreat
srcs = $(wildcard ./*.cpp)
objs = $(srcs:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -pedantic

all: $(NAME)

$(NAME): $(objs)
	c++ $(CXXFLAGS) $(objs) -o $(NAME)

clean:
	$(RM) $(objs)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

