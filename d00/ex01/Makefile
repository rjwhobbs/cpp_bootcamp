NAME = contact_tool

SRC = ./main.cpp ./Contact.class.cpp ./print.cpp ./add_contact.cpp ./search.cpp

STD = c++98

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clang++ -std=$(STD) $(FLAGS) $(SRC) -o $(NAME)

fclean:
	@rm -rf $(NAME);

re: fclean all

