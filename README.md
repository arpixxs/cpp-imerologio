# Olympiad-Vault

## About This Repository

This is my personal, structured library of Olympiad and competitive programming problems with clean, well-documented solutions.
It's my own collection of problems that I solve and revisit while working through Physics and Computer Science topics — mainly problems from contests like ICPC & IPhO, and anything else I find interesting in these fields.

**Languages used:**
- **Physics (IPhO, etc.)** — solved in **Python**, using libraries like NumPy, SciPy, and Matplotlib for numerical work and visualization
- **Competitive Programming (ICPC, etc.)** — solved in **C++** for performance under contest time/memory limits

---

## Repository Structure

```
Olympiad-Vault/
|-- physics/
|   `-- Classical-Mechanics-Problems/
|       `-- IPHO2025.py
|-- competitive-programming/
|   `-- icpc/
`-- README.md
```

---

## What Each Entry Includes

- **Original problem statement** (summarized, with source credited: ICPC, IPhO, etc.)
- **Solution** (readable, commented — Python for physics, C++ for competitive programming)
- **Explanation** of the approach and reasoning
- **Time & space complexity** analysis (for CS/algorithmic problems)
- **Sample test cases** with expected outputs

---

## Getting Started

### Prerequisites

**For Physics problems (Python):**
- Python 3.10+
- NumPy, SciPy, Matplotlib (`pip install numpy scipy matplotlib`)
- Working knowledge of Physics up to at least undergraduate level (mechanics, E&M, thermodynamics, etc.) to follow the reasoning

**For Competitive Programming (C++):**
- A C++17 (or later) compiler — `g++` or `clang++`
- Mathematics and Competitive Programming fundamentals (undergrad level)

---

### Running a Physics Solution (Python)

```bash
pip install numpy scipy matplotlib
python physics/Classical-Mechanics-Problems/IPHO2025.py
```

### Compiling a Competitive Programming Solution (C++)

```bash
g++ -std=c++17 -O2 -Wall -o solution competitive-programming/icpc/001-two-sum.cpp
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

This project is licensed under the [MIT License](LICENSE). Original problem statements remain the property of their respective sources (ICPC & IPhO) and are referenced/credited, not claimed as original content.
