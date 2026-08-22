# ICPC-vault-cpp

## About This Repository

This is my personal, structured library of competitive programming problems with clean, well-documented solutions in C++.
It's my own collection of problems that I solve and revisit while working through Computer Science topics — mainly problems from contests like ICPC and anything else I find interesting.

---

## Repository Structure

```
ICPC-vault-cpp/
├── competitive-programming/ 
│       └── icpc-2025/
│           └── 001-problem1.cpp
└── README.md
```

---

## What Each Entry Includes

- **Original problem statement** (summarized, with source credited: ICPC, Codeforces, etc.)
- **C++ solution** (readable, commented, competition-style)
- **Explanation** of the approach and reasoning
- **Time & space complexity** analysis

---

## Getting Started

### Prerequisites
- A C++17 (or later) compiler — `g++` or `clang++`
- Mathematics and Competitive Programming fundamentals (undergrad level)

### Compiling a Solution
```bash
g++ -std=c++17 -O2 -Wall -o solution competitive-programming/icpc/icpc-2025/001-problem1.cpp
./solution < tests/input1.txt
```

| Flag | Meaning |
|------|---------|
| `g++` | The compiler being used (GNU C++ compiler) |
| `-std=c++17` | Use the C++17 language standard |
| `-O2` | Optimization level 2 — makes the compiled program run faster |
| `-Wall` | Show all warnings (helps catch bugs early) |
| `-o solution` | Name the output executable `solution` (default is `a.out` otherwise) |
| `solution.cpp` | The source file being compiled |

---

## License

This project is licensed under the [MIT License](LICENSE). Original problem statements remain the property of their respective sources (ICPC, Codeforces, etc.) and are referenced/credited, not claimed as original content.
