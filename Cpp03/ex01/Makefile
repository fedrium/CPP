SRC:= *.cpp

NAME:= scavtrap

RM:= rm -rf

all:
	c++ -Wall -Wextra -Werror ${SRC} -o ${NAME} -std=c++98

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all