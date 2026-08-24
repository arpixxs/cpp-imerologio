# ICPC-vault-cpp

## About This Repository

This is a structured library of algorithmic and competitive programming problems, solved and documented in C++ primarily centered around ICPC set problems


---

## Repository Structure

```
ICPC-vault-cpp/
├──icpc-2025/
│       ├── 001-a-skewed-reasoning/
│       │   ├── problem.md        # summarized statement + source credit + samples
│       │   ├── solution.cpp      # actual code
│       │   └── notes.md          # reasoning, false starts, complexity analysis
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
g++ -std=c++17 -O2 -Wall -o solution icpc-2025/01-a-skewed-reasoning.cpp
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
