CXX := g++
CXXFLAGS := -std=c++17

all: compile tests

compile: command.cpp command_funcs.cpp
	@$(CXX) $(CXXFLAGS) -c command_funcs.cpp
	@$(CXX) $(CXXFLAGS) -c command.cpp
	@$(CXX) $(CXXFLAGS) -o ex3_1 command_funcs.o command.o
	
clean:
	@rm -rf ex3_1 command_funcs.o command.o

tests:
	# test 1
	@echo 'tests 1: general command tests'
	@test -z "`./ex3_1 < tests/command.in > tests/command.out.temp 2>&1 ; diff tests/command.out tests/command.out.temp; rm tests/command.out.temp`"
	@echo 'passed'
	# test 2
	@echo 'tests 2: tests blank command'
	@test -z "`./ex3_1 < tests/blank.in | diff tests/blank.out -`"
	@echo 'passed'
	# test 3
	@echo 'tests 3: tests batch file command'
	# ./ex3_1 < tests/batch.in | diff tests/batch.out -
	@test -z "`./ex3_1 < tests/batch.in | diff tests/batch.out -`"
	@echo 'passed'
	# test 4
	@echo 'tests 4: wrong command tests'
	@test -z "`./ex3_1 < tests/wrong_command.in 2> tests/wrong_command.out.temp ; diff tests/wrong_command.out tests/wrong_command.out.temp; rm tests/wrong_command.out.temp`" 
	@echo 'passed'

.PHONY: all compile tests clean 