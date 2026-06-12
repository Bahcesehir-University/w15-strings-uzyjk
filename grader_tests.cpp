/*
==========================================================================
 grader_tests.cpp  -  Autograder for "Strings and File Operations"
 COURSE: CMP1001
--------------------------------------------------------------------------
 This file #includes the student's MainProgram.cpp (renaming its main so
 it does not clash) and tests each function independently.

 Each exercise has its own Catch2 tag so partial points can be awarded by
 running a single test, e.g.:

     make test_1     # Exercise 1 only
     make test_2     # Exercise 2 only
     make grade      # everything

 BUILD (see Makefile):
     g++ -std=c++17 grader_tests.cpp catch_amalgamated.cpp -o grader
==========================================================================
*/

#define main student_main
#include "MainProgram.cpp"
#undef main

#include "catch_amalgamated.hpp"
#include <cstdio>

// Helper: create a temp text file with the given lines.
static void makeFile(const std::string& name,
                     const std::vector<std::string>& lines) {
    std::ofstream out(name);
    for (const auto& l : lines) out << l << "\n";
    out.close();
}

// ---- Section 2: countVowels -------------------------------------- [s2a]
TEST_CASE("countVowels", "[s2a]") {
    REQUIRE(countVowels("") == 0);
    REQUIRE(countVowels("xyz") == 0);
    REQUIRE(countVowels("aeiou") == 5);
    REQUIRE(countVowels("AEIOU") == 5);
    REQUIRE(countVowels("Programming") == 3);
    REQUIRE(countVowels("Hello World") == 3);
}

// ---- Section 2: toUpperCase -------------------------------------- [s2b]
TEST_CASE("toUpperCase", "[s2b]") {
    REQUIRE(toUpperCase("") == "");
    REQUIRE(toUpperCase("hello") == "HELLO");
    REQUIRE(toUpperCase("hello123") == "HELLO123");
    REQUIRE(toUpperCase("MixEd Case!") == "MIXED CASE!");
}

// ---- Exercise 1: reverseString ----------------------------------- [ex1]
TEST_CASE("reverseString", "[ex1]") {
    REQUIRE(reverseString("") == "");
    REQUIRE(reverseString("a") == "a");
    REQUIRE(reverseString("hello") == "olleh");
    REQUIRE(reverseString("abc def") == "fed cba");
}

// ---- Exercise 2: isPalindrome ------------------------------------ [ex2]
TEST_CASE("isPalindrome", "[ex2]") {
    REQUIRE(isPalindrome("") == true);
    REQUIRE(isPalindrome("a") == true);
    REQUIRE(isPalindrome("level") == true);
    REQUIRE(isPalindrome("racecar") == true);
    REQUIRE(isPalindrome("Level") == false);
    REQUIRE(isPalindrome("hello") == false);
}

// ---- Exercise 3: countWords -------------------------------------- [ex3]
TEST_CASE("countWords", "[ex3]") {
    REQUIRE(countWords("") == 0);
    REQUIRE(countWords("   ") == 0);
    REQUIRE(countWords("hello") == 1);
    REQUIRE(countWords("hello world") == 2);
    REQUIRE(countWords("  hi   there  ") == 2);
    REQUIRE(countWords("one two three four") == 4);
}

// ---- Exercise 4: replaceChar ------------------------------------- [ex4]
TEST_CASE("replaceChar", "[ex4]") {
    REQUIRE(replaceChar("", 'a', 'b') == "");
    REQUIRE(replaceChar("banana", 'a', 'o') == "bonono");
    REQUIRE(replaceChar("hello", 'l', 'L') == "heLLo");
    REQUIRE(replaceChar("abc", 'z', 'y') == "abc");
}

// ---- Exercise 5: writeLines -------------------------------------- [ex5]
TEST_CASE("writeLines", "[ex5]") {
    std::string fn = "test_write.txt";
    std::remove(fn.c_str());
    std::vector<std::string> lines = {"alpha", "beta", "gamma"};
    REQUIRE(writeLines(fn, lines) == true);

    // verify contents independently
    std::ifstream in(fn);
    REQUIRE(in.is_open());
    std::string l;
    std::vector<std::string> got;
    while (std::getline(in, l)) got.push_back(l);
    in.close();
    REQUIRE(got.size() == 3);
    REQUIRE(got[0] == "alpha");
    REQUIRE(got[1] == "beta");
    REQUIRE(got[2] == "gamma");
    std::remove(fn.c_str());
}

// ---- Exercise 6: readLines --------------------------------------- [ex6]
TEST_CASE("readLines", "[ex6]") {
    std::string fn = "test_read.txt";
    makeFile(fn, {"one", "two", "three"});
    auto got = readLines(fn);
    REQUIRE(got.size() == 3);
    REQUIRE(got[0] == "one");
    REQUIRE(got[2] == "three");
    std::remove(fn.c_str());

    auto missing = readLines("does_not_exist_12345.txt");
    REQUIRE(missing.size() == 0);
}

// ---- Exercise 7: countLinesInFile -------------------------------- [ex7]
TEST_CASE("countLinesInFile", "[ex7]") {
    std::string fn = "test_count.txt";
    makeFile(fn, {"a", "b", "c", "d"});
    REQUIRE(countLinesInFile(fn) == 4);
    std::remove(fn.c_str());
    REQUIRE(countLinesInFile("does_not_exist_12345.txt") == -1);
}

// ---- Challenge A: wordCountInFile -------------------------------- [chA]
TEST_CASE("wordCountInFile", "[chA]") {
    std::string fn = "test_wc.txt";
    makeFile(fn, {"the cat sat", "on the mat", "end"});
    REQUIRE(wordCountInFile(fn) == 7);
    std::remove(fn.c_str());
    REQUIRE(wordCountInFile("does_not_exist_12345.txt") == -1);
}

// ---- Challenge B: censorWord ------------------------------------- [chB]
TEST_CASE("censorWord", "[chB]") {
    std::string fn = "test_censor.txt";
    makeFile(fn, {"the cat sat", "cat dog cat"});
    REQUIRE(censorWord(fn, "cat") == "the *** sat\n*** dog ***");
    std::remove(fn.c_str());

    makeFile(fn, {"no match here"});
    REQUIRE(censorWord(fn, "cat") == "no match here");
    std::remove(fn.c_str());

    REQUIRE(censorWord("does_not_exist_12345.txt", "cat") == "");
}
