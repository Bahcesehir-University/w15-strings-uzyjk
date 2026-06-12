# Lab: Strings and File Operations

## Course Information
- **Course:** CMP1001 – Introduction to Programming (C++)
- **Lab Duration:** 60 minutes
- **File to submit:** `MainProgram.cpp`

## Objective
Learn to manipulate text with the C++ `std::string` class and to read from
and write to text files using `ifstream` and `ofstream`. By the end you will
have written a small set of reusable string and file-handling functions.

## Prerequisites
- Basic C++ syntax: `cout`, `cin`, variables, `if`/`else`
- Simple loops (`for`, `while`)
- A working `g++` compiler (C++17)

## What You Will Learn
- Indexing and looping over characters in a `string`
- Building new strings and transforming text (reverse, replace, uppercase)
- Counting vowels and words
- Detecting palindromes
- Writing lines to a file and reading them back
- Counting lines and words in a file
- Combining string and file skills in two challenge problems

## Lab Structure
| Section | Focus | What you do |
|--------|-------|-------------|
| 1 — Warm-up | `cin`/`cout`, variables, conditions | Greet the user, compare two numbers |
| 2 — Core Concepts | Basic string handling | `countVowels`, `toUpperCase` |
| 3 — Guided Exercises | Strings + files | `reverseString`, `isPalindrome`, `countWords`, `replaceChar`, `writeLines`, `readLines`, `countLinesInFile` |
| 4 — Challenge | Real-world style | `wordCountInFile`, `censorWord` |

All work goes in the single file `MainProgram.cpp`. Do **not** create header
files or split into multiple files. Do **not** rename the functions — the
autograder depends on their names and signatures.

## How to Compile & Run
```bash
g++ MainProgram.cpp -o lab
./lab
```

## Autograder (optional, for self-checking)
The instructor provides `grader_tests.cpp`, `catch_amalgamated.cpp/.hpp`, and a
`Makefile`. To check your work:
```bash
make grade        # run ALL tests
make test_1       # run only Exercise 1 (reverseString)
make test_2       # run only Exercise 2 (isPalindrome)
# ... up to test_7, plus test_s2a, test_s2b, test_chA, test_chB
```
Each function is tested independently so you can earn **partial credit** for
the parts you finish.

## Submission Instructions
1. Complete every `// TODO` in `MainProgram.cpp`.
2. Make sure the file compiles with no errors.
3. Commit and push to your GitHub Classroom repository:
   ```bash
   git add MainProgram.cpp
   git commit -m "Complete Strings and File Operations lab"
   git push
   ```

## Grading Criteria
| Criterion | Weight |
|-----------|-------:|
| Correctness (passes tests) | 50% |
| Code Quality (readable, clean, good names) | 20% |
| Completion (all sections attempted) | 20% |
| Challenge (Challenge A & B) | 10% |

See `GRADING_RUBRIC.md` for the per-test point breakdown.

## Estimated Time Breakdown
| Section | Time |
|---------|-----:|
| 1 — Warm-up | 5–10 min |
| 2 — Core Concepts | 10–15 min |
| 3 — Guided Exercises | 25–30 min |
| 4 — Challenge | 10 min |

## Tips for Students
- A `std::string` behaves like an array of `char`: use `text[i]` and `text.size()`.
- Build a result string by appending with `+=`; don't try to modify a `const&` parameter.
- For files, **always** check `is_open()` before reading or writing.
- `getline(stream, line)` reads one line at a time and returns false at end-of-file — perfect for a `while` loop.
- Test small inputs first (empty string, one word) before the big cases.
- Compile often. Fix the first error before worrying about later ones.
