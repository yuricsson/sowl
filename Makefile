FLAGS = -Wall -Wextra -Werror
CC = g++ $(FLAGS)

all : main

main : main.o realty.o
	$(CC) main.o realty.o -o main

main.o : main.cpp
	$(CC) -c main.cpp

realty.o : realty.cpp
	$(CC) -c realty.cpp

clean:
	rm -fr *.o main

rebuild: clean all
