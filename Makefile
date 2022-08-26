FLAGS=-Wall -Wextra -Wpedantic
all:
	g++ $(FLAGS) main.cpp unit_test.cpp inoutput.cpp function.cpp -o main