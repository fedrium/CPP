SRC:= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

RM:= rm -rf

all:
	c++ -Wall -Wextra -Werror -fsanitize=address -g3 ${SRC} -o zombie

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all