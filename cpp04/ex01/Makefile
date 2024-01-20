NAME = animal
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

run: all
	./$(NAME)

out: all
	./$(NAME) 2>/dev/null

err: all
	./$(NAME) 1>/dev/null

.PHONY: all clean fclean re
