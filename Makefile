# ==========================================================================
#  Makefile - CMP1001 "Strings and File Operations" lab
# --------------------------------------------------------------------------
#  make            -> build the student program (lab)
#  make grader     -> build the autograder
#  make grade      -> run ALL tests
#  make test_1 ... -> run a single exercise (partial points)
# ==========================================================================

CXX      = g++
CXXFLAGS = -std=c++17 -Wall

# Student program
lab: MainProgram.cpp
	$(CXX) $(CXXFLAGS) MainProgram.cpp -o lab

# Autograder (includes the student's MainProgram.cpp)
grader: grader_tests.cpp catch_amalgamated.cpp MainProgram.cpp
	$(CXX) $(CXXFLAGS) grader_tests.cpp catch_amalgamated.cpp -o grader

# Run everything
grade: grader
	./grader

# ---- Per-exercise targets (partial points) -------------------------------
test_s2a: grader
	./grader "[s2a]"
test_s2b: grader
	./grader "[s2b]"
test_1: grader
	./grader "[ex1]"
test_2: grader
	./grader "[ex2]"
test_3: grader
	./grader "[ex3]"
test_4: grader
	./grader "[ex4]"
test_5: grader
	./grader "[ex5]"
test_6: grader
	./grader "[ex6]"
test_7: grader
	./grader "[ex7]"
test_chA: grader
	./grader "[chA]"
test_chB: grader
	./grader "[chB]"

clean:
	rm -f lab grader demo.txt test_*.txt

.PHONY: grade clean test_s2a test_s2b test_1 test_2 test_3 test_4 test_5 test_6 test_7 test_chA test_chB
