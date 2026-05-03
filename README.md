# CSAPP Homework & Labs

This repository contains my homework solutions and lab implementations for *Computer Systems: A Programmer's Perspective* (CS:APP, 3rd Edition), organized by chapter.

> ⚠️ **Academic Integrity**
> If you are currently taking a course that uses this material, please adhere to your institution's academic honesty policies. The code in this repository is for learning purposes only; direct plagiarism may violate course rules.

## Directory Structure

.
├── ch02-data
│   ├── homework/ #Programming homework in book
│   └── labs #Some casual exercises
│       ├── build/ #Compiled binaries
│       └── makefile
├── ch03-machine
│   ├── homework
│   └── labs
├── ch04-processor
│   ├── homework
│   └── labs
│ ...
├── Makefile
└── README.md


## Chapter Overview

| Chapter | Topic | Homework | Labs |
|---------|-------|:--------:|:----:|
| ch02-data | Representing and Manipulating Information | [ ] | [ ] |
| ch03-machine | Machine-Level Representation of Programs | [ ] | [ ] |
| ch04-processor | Processor Architecture | [ ] | [ ] |

## Environment

- **OS**: Arch Linux x86_64
- **Compiler**: GCC (supports C99 and x86-64 assembly)
- **Tools**: Make, GDB, objdump, Valgrind, etc.

## Build & Run

Each chapter's lab directory contains its own `makefile`. You can build individual targets as follows:

```bash
# Build all labs
make all

# Build labs for a specific chapter
cd ch02-data/labs
make

# Run compiled binaries
./build/append
./build/reducto
```

## Progress

- [ ] Chapter 2 — Representing and Manipulating Information
- [ ] Chapter 3 — Machine-Level Representation of Programs
- [ ] Chapter 4 — Processor Architecture
- [ ] Chapter 5 — Optimizing Program Performance
- [ ] Chapter 6 — The Memory Hierarchy
- [ ] Chapter 7 — Linking
- [ ] Chapter 8 — Exceptional Control Flow
- [ ] Chapter 9 — Virtual Memory
- [ ] Chapter 10 — System-Level I/O
- [ ] Chapter 11 — Network Programming
- [ ] Chapter 12 — Concurrent Programming

Check off items above as you progress through the book (`[ ]` → `[x]`).

## References

- [CS:APP Official Site](https://csapp.cs.cmu.edu/)
- *Computer Systems: A Programmer's Perspective*, 3rd Edition — Bryant & O'Hallaron

## License

This repository is for personal study only and is provided without any commercial license.