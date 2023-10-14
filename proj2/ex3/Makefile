CXX := g++
CXXFLAGS := -std=c++17

all: compile tests

compile: ex3_main.cpp board.h
	@$(CXX) $(CXXFLAGS) -c ex3_main.cpp -o main.o
	@$(CXX) $(CXXFLAGS) main.o -o ex3
	
clean:
	@rm -rf ex3 main.o func.o inventory.o

tests:
	# test 1
	@echo 'tests: 19*19 board'
	@test -z "`./ex3 > tests/19x19.out.temp 2>&1 ; diff tests/19x19.out tests/19x19.out.temp; rm tests/19x19.out.temp`" #
	@echo 'passed'

.PHONY: all compile tests clean 