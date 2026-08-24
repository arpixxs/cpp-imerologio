# ICPC-vault-cpp

A personal collection of **ICPC competitive-programming problems solved in C++**, with the emphasis on understanding the reasoning

## Repository Structure

```text
ICPC-vault-cpp/
├── ICPC-2025/
│   └── 01-a-skewed-reasoning/
│       ├── problem.md
│       ├── solution.cpp
│       └── notes.md
└── README.md
```

### Problem directory

Each problem directory contains:

| File | Purpose |
|---|---|
| `problem.md` | Paraphrased problem statement, source/contest information, samples, approach, and complexity |
| `solution.cpp` | C++17 implementation |
| `notes.md` | Personal reasoning, observations, false starts, and implementation insights |

The repository may grow with more contest years and problems that I will add


## Getting Started

### Prerequisites

You need:

- a C++17-or-newer compiler;
- `g++` (recommended) or `clang++`;
- a terminal such as PowerShell, Command Prompt, or a Unix shell.

No external libraries are required by the current problems


## Compile and Run

From the repository root:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -o ICPC-2025/01-a-skewed-reasoning/solution.exe ICPC-2025/01-a-skewed-reasoning/solution.cpp
.\ICPC-2025\01-a-skewed-reasoning\solution.exe


## Compiler Flags

| Flag | Purpose |
|---|---|
| `-std=c++17` | Compile using the C++17 standard |
| `-O2` | Enable compiler optimizations |
| `-Wall` | Enable common compiler warnings |
| `-pedantic` | Warn about non-standard C++ constructs |
| `-o ...` | Choose the name and location of the executable |


For each problem, sample inputs and outputs are documented in `problem.md`.
The `notes.md` files are intentionally more personal and exploratory

## Attribution

Problem statements and contest material belong to their respective organizers and authors.

The repository contains paraphrased summaries for study and documentation, with the original source credited in each problem's `problem.md`.

Original problem statements are not claimed as original work.

## License

This project is licensed under the [MIT License](LICENSE).

You are free to use, modify, and distribute the code under the terms of the license.

Problem statements and contest materials remain the property of their respective organizers and authors. They are paraphrased and credited for educational and documentation purposes and are not claimed as original work.
