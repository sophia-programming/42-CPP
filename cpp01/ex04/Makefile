NAME = replace
srcs = $(wildcard ./*.cpp)
objs = $(srcs:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -pedantic

all: $(NAME)

$(NAME): $(objs)
	c++ $(CXXFLAGS) $(objs) -o $(NAME)

clean:
	$(RM) $(objs)
	$(RM) $(wildcard ./*.replace)

fclean: clean
	$(RM) $(NAME)
re: fclean all

run: all
	./$(NAME)

test: all
	chmod -R 777 ./test/test.sh
	bash ./test/test.sh

.PHONY: all clean fclean re test run
