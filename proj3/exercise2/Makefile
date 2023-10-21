CXX := g++
CXXFLAGS := -std=c++17

all: compile tests

compile: selection.cpp CLLNode.cpp
	@$(CXX) $(CXXFLAGS) -c selection.cpp -o main.o
	@$(CXX) $(CXXFLAGS) -c CLLNode.cpp -o func.o
	@$(CXX) $(CXXFLAGS) main.o func.o -o ex2
	
clean:
	@rm -rf ex2 main.o func.o 

tests:
	# test 1
	@echo 'tests: 8 peoples, k=2'
	@test -z "`./ex2 > tests/8_2.out.temp 2>&1 ; diff tests/8_2.out tests/8_2.out.temp; rm tests/8_2.out.temp`" #
	@echo 'passed'

.PHONY: all compile tests clean 