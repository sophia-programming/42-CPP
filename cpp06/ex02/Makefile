NAME = Base
srcs = $(wildcard srcs/*.cpp)
includes = -I ./includes
objs = $(srcs:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 $(includes)

all: $(NAME)

$(NAME): $(objs)
	c++ $(CXXFLAGS) $(includes) $(objs) -o $(NAME)

clean:
	$(RM) $(objs)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
