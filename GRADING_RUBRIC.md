# Grading Rubric — Strings and File Operations

Total: **100 points** (90 functional + 10 quality)

Each function is graded by its own test target so partial credit is easy.

| Target | Function | Tag | Points |
|--------|----------|-----|-------:|
| `make test_s2a` | `countVowels` | `[s2a]` | 8 |
| `make test_s2b` | `toUpperCase` | `[s2b]` | 8 |
| `make test_1` | `reverseString` | `[ex1]` | 8 |
| `make test_2` | `isPalindrome` | `[ex2]` | 8 |
| `make test_3` | `countWords` | `[ex3]` | 8 |
| `make test_4` | `replaceChar` | `[ex4]` | 8 |
| `make test_5` | `writeLines` | `[ex5]` | 10 |
| `make test_6` | `readLines` | `[ex6]` | 10 |
| `make test_7` | `countLinesInFile` | `[ex7]` | 7 |
| `make test_chA` | `wordCountInFile` | `[chA]` | 7 |
| `make test_chB` | `censorWord` | `[chB]` | 8 |
| | **Functional subtotal** | | **90** |
| (manual) | Code quality / readability | | 10 |

## Notes for the Grader
- A function earns its points only if **all** assertions for its tag pass.
  Optionally, award proportional credit by counting passing `REQUIRE`s.
- Run a single target to grade one function: `make test_3`.
- Run everything at once: `make grade`.
- Reference solution (`MainProgram_teacher.cpp`) passes **47/47 assertions**.
- Code quality (10 pts): meaningful names, consistent indentation, no dead
  code, sensible structure. Judged by reading the submission, not by tests.
