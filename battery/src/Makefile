CC = gcc; 
CXX = g++;
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g -O0
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++11 -g -O0
LDFLAGS = -lm
OBJ = battery.o
BIN = battery

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN) $(LDFLAGS)

battery_main: battery_main.o battery.o
	$(CC) $(CFLAGS) battery_main.o battery.o -o battery_main $(LDFLAGS)

battery.o: battery.c battery.h
	$(CC) $(CFLAGS) -c battery.c -o battery.o

controller.o: controller.c controller.h
	$(CC) $(CFLAGS) -c controller.c -o controller.o

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all clean

