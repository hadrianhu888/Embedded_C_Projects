CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -c
CXXFLAGS = -Wall -Wextra -c

all: main

main: main.o utils.o
	$(CXX) $^ -o ../build/$@

main.o: main.c utils.hpp
	$(CC) $(CFLAGS) $< -o $@

utils.o: utils.c utils.hpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o ../build/main
