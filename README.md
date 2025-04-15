# TownPathfinder (DataStracture-Ex1)
TownPathfinder is a C++ program that calculates the shortest distance between two towns in a country using two different approaches:
1. **Recursive Depth-First Search (DFS)**
2. **Iterative DFS using a custom Stack**

This is a simple educational project that demonstrates key data structures and algorithms, including linked lists, stacks, and depth-first search traversal.

---

## 🧠 Features

- Reads towns and roads from user input
- Validates the input (e.g. road duplication, invalid IDs)
- Constructs an adjacency list graph representation
- Computes the preferred (shortest path) distance using:
  - **Recursive DFS**
  - **Iterative DFS using Stack**
- Compares results of both approaches

---

## 🔧 Technology & Concepts

### Language
- **C++** (Modern features, but standard compatible with C++11 and above)

### Core Concepts
- **Graph Representation** using Adjacency Lists
- **Custom Linked List and Node Structures**
- **Coloring Algorithm** for visited nodes
- **Recursive Function Calls**
- **Manual Stack Implementation**
- **Object-Oriented Design** (Encapsulation of Towns, Roads, Paths)

### Environment
- Built with **Visual Studio** (solution and project files included)
- Cross-platform compatible with any C++ compiler

---

## 📁 Project Structure

```
.
├── ds_ex1.sln                      # Visual Studio Solution
├── ds_ex1/                        # Source directory
│   ├── *.cpp                      # Implementation files
│   ├── *.h                        # Header files
│   ├── ds_ex1.vcxproj            # Project configuration
│   ├── ds_ex1.vcxproj.filters    # Visual Studio filters
├── README.md
```

---

## 🚀 Getting Started

### Compile and Run (Linux / Mac / CLI)
```bash
g++ -std=c++11 -o TownPathfinder *.cpp
./TownPathfinder
```

### Or use Visual Studio
1. Open `ds_ex1.sln`
2. Build the solution
3. Run via Visual Studio's debugger or terminal

---

## 👨‍💻 Input Format

- First line: Number of towns and number of roads
- Next N lines: Road definitions (pairs of town IDs)
- Final line: Two town IDs between which to calculate the preferred path

Example:
```
5 4
1 2
2 3
3 4
4 5
1 5
```

---

## 🧪 Sample Output

```
Preferred distance (recursive algorithm): 4
Preferred distance (iterative stack algorithm): 4
```

---

## 📜 License

This project is for educational use and is not currently licensed for commercial distribution.

---

## 🙌 Credits

Developed as part of a data structures coursework project, focusing on hands-on application of C++ concepts in a graph traversal problem space.
