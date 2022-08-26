FLAGS=-Wall -Wextra -Wpedantic

SRC=main.cpp unit_test.cpp inoutput.cpp function.cpp

all:
	g++ $(FLAGS) $(SRC) -o main