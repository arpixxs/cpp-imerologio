# Olympiad-vault-cpp

## About This Repository

This is my personal, structured library of Olympiad and competitive programming problems with clean, well-documented solutions in C++.
It's my own collection of problems that I solve and revisit while working through Physics and Computer Science topics — mainly problems from contests like ICPC & IPhO, and anything else I find interesting in these fields, all solved using C++ only.

---

## Repository Structure

```
Olympiad-vault-cpp/
├── physics/
├── competitive-programming/
└── README.md
```

---

Each entry includes:
- **Original problem statement** (with source: IOI, IPhO, IMO, Codeforces, etc.)
- **C++ solution** (readable, commented, competition-style)
- **Explanation** of the approach and reasoning
- **Time & space complexity** analysis (for CS/algorithmic problems)
- **Sample test cases** with expected outputs

---

## Getting Started

### Prerequisites
- A C++17 (or later) compiler — `g++` or `clang++`
- Working knowledge of Physics up to at least undergraduate level (mechanics, E&M, thermodynamics, etc.) to follow the reasoning in the Physics section
-  Mathematics and Competitive Programming (undergrad level)

### Compiling a Solution
```bash
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
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


---

## License

This project is licensed under the [MIT License](LICENSE). Original problem statements remain the property of their respective sources ( ICPC & IPHO) and are referenced/credited, not claimed as original content.
