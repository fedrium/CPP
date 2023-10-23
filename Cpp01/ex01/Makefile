SRC:= main.cpp Zombie.cpp zombieHorde.cpp

NAME:= zombie

RM:= rm -rf

all:
	c++ -Wall -Wextra -Werror -fsanitize=address -g3 ${SRC} -o ${NAME}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all
