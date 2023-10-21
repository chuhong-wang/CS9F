CXX := g++
CXXFLAGS := -std=c++17

all: compile tests

compile:  amoebamain.cpp  amoebas.cpp     amoebas.h
	@$(CXX) $(CXXFLAGS) -c amoebamain.cpp -o main.o
	@$(CXX) $(CXXFLAGS) -c amoebas.cpp -o func.o
	@$(CXX) $(CXXFLAGS) main.o func.o -o ex3
	
clean:
	@rm -rf ex3 main.o func.o 

tests:
	# test 1
	@echo 'tests: amoeba tree'
	@test -z "`./ex3 > tests/test.out.temp 2>&1 ; diff tests/text.out tests/test.out.temp; rm tests/test.out.temp`" #
	@echo 'passed'

.PHONY: all compile tests clean 