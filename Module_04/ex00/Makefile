SRC = main.cpp \
	Animal.cpp \
	Cat.cpp \
	Dog.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp 

RM = rm -f
CPPFLAGS = c++ -Wall -Wextra -Werror -std=c++98

NAME = Animal

all: $(NAME)

$(NAME):
	$(CPPFLAGS) -o $(NAME) $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re