FLAGS = -Wall -Wextra -Werror
CC = g++ $(FLAGS)

all : main

main :
	$(CC) realty.cpp -o main

clean:
	rm -fr *.o main

rebuild: clean all
 