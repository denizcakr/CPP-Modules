SRC = main.cpp \
		Harl.cpp
RM = rm -f
CPPFLAGS = c++ -Wall -Wextra -Werror -std=c++98

NAME = harlFilter

all: $(NAME)

$(NAME):
	$(CPPFLAGS) -o $(NAME) $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re