# C++ Projects 

A growing collection of C++ projects, organized by difficulty level — from starting Level 1 toward advanced.

This repository is meant to document my journey of learning and mastering C++, one project at a time. Each project focuses on a specific concept, data structure, algorithm, or ICPC problem set.


##  How Projects Are Organized

Projects are grouped into levels based on difficulty and the concepts they cover — starting from `Level-1` and moving up as complexity increases. New levels and projects are added continuously, so this repository is a work in progress.

##  Repository Structure

```
├── Level-1-projects/
│   └── Tensor-calculator.cpp
├── Level-2-projects/
├── Level-3-projects/
├── ...
└── Level-Advanced-projects/
     ICPC-vault-cpp/
           ICPC-2025/
               └── 01-a-skewed-reasoning/
               ├── problem.md
               ├── solution.cpp
               └── notes.md
                   └── README.md
```

Each `Level-X-projects` folder contains standalone `.cpp` files (or sub-folders for larger projects) for that difficulty tier. Alongside the leveled projects, the repository will also include:

- **DSA Problems** — solutions to data structures and algorithms problems (arrays, linked lists, trees, graphs, dynamic programming, etc.), used for interview prep and concept reinforcement and icpc contest problems 
- **Computational Physics Mini-Projects** — small simulations and numerical solutions to physics problems (e.g., projectile motion, N-body simulations, numerical integration, wave/heat equation solvers), used to apply C++ to real-world scientific computing


##  Featured Project

### Tensor-calculator.cpp (Level 1)
A beginner-level program that performs basic tensor/matrix-style calculations, introducing core C++ concepts such as arrays, loops, functions, and numerical computation.
### ICPC 2025 problem (Level advance)

## Requirements

- A C++ compiler (GCC, Clang, or MSVC)
- C++11 or later recommended
- DSA concepts knowledge
- - a terminal such as PowerShell, Command Prompt, or a Unix shell.


## Running a Project

1. Navigate to the project's folder.
2. Compile the `.cpp` file using your preferred compiler:
   ```bash
   g++ Tensor-calculator.cpp -o tensor_calculator
   ```
3. Run the executable:
   ```bash
   ./tensor_calculator
   ```
 ## Compile and Run the ICPC problem

From the repository root:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -o ICPC-2025/01-a-skewed-reasoning/solution.exe ICPC-2025/01-a-skewed-reasoning/solution.cpp
.\ICPC-2025\01-a-skewed-reasoning\solution.exe
```
## Compiler Flags

| Flag | Purpose |
|---|---|
| `-std=c++17` | Compile using the C++17 standard |
| `-O2` | Enable compiler optimizations |
| `-Wall` | Enable common compiler warnings |
| `-pedantic` | Warn about non-standard C++ constructs |
| `-o ...` | Choose the name and location of the executable |


## Progress

This repository will keep expanding with new projects as I advance through more complex topics — including data structures, algorithms, object-oriented design, multi-threading, and more.

## Contributing

This is primarily a personal learning repository

## Attribution

Problem statements and contest material belong to their respective organizers and authors.

The repository contains paraphrased summaries for study and documentation, with the original source credited in each problem's `problem.md`.

Original problem statements are not claimed as original work.


## License

This project is open source and available for learning purposes and licensed under the [MIT License](LICENSE)


---
