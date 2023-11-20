NAME = megaphone
srcs = $(wildcard ./*.cpp)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(srcs)
	c++ $(srcs) $(CXXFLAGS) -o $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	chmod -R 777 test.sh
	./test.sh

.PHONY: all clean fclean re test
