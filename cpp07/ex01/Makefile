SRC:= *.cpp

NAME:= iter

RM:= rm -rf

all:
	c++ -Wall -Wextra -Werror -std=c++98 ${SRC} -o ${NAME}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all