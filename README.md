# C++ Projects 

A growing collection of C++ projects, organized by difficulty level — from starting Level 1 toward advanced.

This repository is meant to document my journey of learning and mastering C++, one project at a time. Each project focuses on a specific concept, data structure, algorithm, or ICPC problem set.


##  How Projects Are Organized

Projects are grouped into levels based on difficulty and the concepts they cover — starting from `Level-1` and moving up as complexity increases. New levels and projects are added continuously, so this repository is a work in progress.

##  Repository Structure

```
└── Level-Advanced-projects/
     ICPC-vault-cpp/
           ICPC-2025/
               └── 01-a-skewed-reasoning/
               ├── problem.md
               ├── solution.cpp
               └── notes.md
                   └── README.md
├── Level-1-projects/   #DSA problems with difficulty level 1 
├── Level-2-projects/   #DSA problems with difficulty level 2
├── Level-3-projects/   #DSA problems with difficulty level 3

```

Each `Level-X-projects` folder contains standalone `.cpp` files (or sub-folders for larger projects) for that difficulty tier. Alongside the leveled projects, the repository will also include:

- **DSA Problems** — solutions to data structures and algorithms problems (arrays, linked lists, trees, graphs, dynamic programming, etc.), used for interview prep and concept reinforcement and icpc contest problems 
- **Computational Physics Mini-Projects** — small simulations and numerical solutions to physics problems (e.g., projectile motion, N-body simulations, numerical integration, wave/heat equation solvers), used to apply C++ to real-world scientific computing


## Requirements

- A C++ compiler (GCC, Clang, or MSVC)
- C++11 or later recommended
- DSA concepts knowledge
- - a terminal such as PowerShell, Command Prompt, or a Unix shell.


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

This is primarily a personal learning repository created by me in way to master C++ and some cool projects 

## Attribution

Problem statements and contest material belong to their respective organizers and authors.

The repository contains paraphrased summaries for study and documentation, with the original source credited in each problem's `problem.md`.

Original problem statements are not claimed as original work.


## License

This project is open source and available for learning purposes and licensed under the [MIT License](LICENSE)


---
