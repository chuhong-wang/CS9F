CXX := g++
CXXFLAGS := -std=c++17

all: compile tests

compile: ex2_main.cpp func.cpp inventory.cpp inventory.h
	@$(CXX) $(CXXFLAGS) -c ex2_main.cpp -o main.o
	@$(CXX) $(CXXFLAGS) -c func.cpp -o func.o
	@$(CXX) $(CXXFLAGS) -c inventory.cpp -o inventory.o
	@$(CXX) $(CXXFLAGS) main.o func.o inventory.o -o ex3_2
	
clean:
	@rm -rf ex3_1 main.o func.o inventory.o

tests:
	# test 1
	@echo 'tests 1: general command tests'
	@test -z "`./ex3_2 < tests/command.in > tests/command.out.temp 2>&1 ; diff tests/command.out tests/command.out.temp; rm tests/command.out.temp`" #
	@echo 'passed'
	# test 2
	@echo 'tests 2: tests blank command'
	@test -z "`./ex3_2 < tests/blank.in | diff tests/blank.out -`"
	@echo 'passed'
	# test 3
	@echo 'tests 3: tests batch file command'
	# ./ex3_2 < tests/batch.in | diff tests/batch.out -
	@test -z "`./ex3_2 < tests/batch.in | diff tests/batch.out -`"
	@echo 'passed'
	# test 4
	@echo 'tests 4: wrong command tests'
	@test -z "`./ex3_2 < tests/wrong_command.in 2> tests/wrong_command.out.temp ; diff tests/wrong_command.out tests/wrong_command.out.temp; rm tests/wrong_command.out.temp`" 
	@echo 'passed'

.PHONY: all compile tests clean 