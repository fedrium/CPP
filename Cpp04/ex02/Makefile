SRC:= *.cpp

NAME:= abstract

RM:= rm -rf

all:
	c++ -Wall -Wextra -Werror -g ${SRC} -o ${NAME}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all