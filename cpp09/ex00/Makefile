NAME = btc
srcs = $(wildcard *.cpp)
objs = $(srcs:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -pedantic

all: $(NAME)

$(NAME): $(objs)
	clang++ $(CXXFLAGS) -o $(NAME) $(objs)

clean:
	$(RM) $(objs)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
