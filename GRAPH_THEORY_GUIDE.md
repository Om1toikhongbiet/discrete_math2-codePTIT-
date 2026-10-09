# 📘 Discrete Math 2: The Ultimate Graph Theory Guide

Welcome to Graph Theory! In Discrete Math 2 (Toán Rời Rạc 2), almost every problem revolves around understanding how points (**Vertices/Đỉnh**) are connected by lines (**Edges/Cạnh**) and how to navigate them using code.

Here is the master roadmap of everything you need to know to solve 99% of the problems in this subject.

---

## 1. How to Represent a Graph in Code
You cannot put a drawing into C++. You have to translate it into arrays. There are two main ways:

### A. Adjacency Matrix (Ma trận kề)
A 2D array `int adj[N][N]` where `adj[u][v] = 1` means there is a road from `u` to `v`.
* **Pros**: Super fast to check if an edge exists between two specific nodes ($O(1)$).
* **Cons**: Wastes a lot of memory. To find all neighbors of `u`, you have to loop from `1` to `N`, which is very slow if $N$ is large ($O(N)$). 
* *Use when*: $N \le 1000$ and you need to quickly check specific edges.

### B. Adjacency List (Danh sách kề) - 🌟 The Golden Standard
An array of dynamic lists: `vector<int> adj[N]`. `adj[u]` only contains the exact nodes connected to `u`.
* **Pros**: Extremely fast to iterate through neighbors. Saves memory. Prevents "Time Limit Exceeded" (TLE).
* **Cons**: Slightly harder to check if a specific edge (u, v) exists.
* *Use when*: Always! This should be your default choice for coding graph problems.

---

## 2. Graph Traversal (Walking through the graph)
How do we visit all the nodes without getting stuck in an infinite loop? We use a `visited` array and one of these two algorithms:

### A. Depth-First Search (DFS - Tìm kiếm theo chiều sâu)
* **How it works**: Imagine exploring a maze. You keep walking down a path until you hit a dead end, then you **backtrack** (quay lui) to the last intersection and try another path.
* **Code Implementation**: Built using **Recursion** (đệ quy).
* **Best used for**: 
  - Finding cycles (Chu trình).
  - Checking connectivity (Liên thông).
  - Generating permutations / Hamiltonian Paths.

### B. Breadth-First Search (BFS - Tìm kiếm theo chiều rộng)
* **How it works**: Imagine dropping a stone in water. The ripples spread outward level by level. You visit all immediate neighbors first, then their neighbors, and so on.
* **Code Implementation**: Built using a **Queue** (hàng đợi).
* **Best used for**: 
  - Finding the **shortest path** on an unweighted graph (Đường đi ngắn nhất).
  - Spreading algorithms (like a virus infection).

---

## 3. Core Graph Properties
Before writing complex algorithms, you must understand the graph's structure:
* **Directed (Có hướng) vs Undirected (Vô hướng)**: Can you travel both ways on a road, or is it a one-way street?
* **Degree (Bậc)**: 
  * *Undirected*: Number of edges connected to a node.
  * *Directed*: In-Degree (Bậc vào - roads entering) and Out-Degree (Bậc ra - roads leaving).
* **Connected Components (Thành phần liên thông)**: Is the graph one single piece, or is it broken into isolated islands? (Use DFS/BFS to count them).

---

## 4. Famous Cycles & Paths (Your Assignments!)
These are the classic boss fights of Discrete Math 2:

### A. Eulerian Path / Cycle (Đường đi / Chu trình Euler)
* **Rule**: You must cross **every single EDGE (cạnh) exactly once**.
* **The Trick**: You don't need to guess! You just check the **Degrees**.
  - *Euler Cycle*: Exists ONLY IF every single node has an **Even Degree** (bậc chẵn).
  - *Euler Path*: Exists ONLY IF exactly zero or two nodes have an **Odd Degree** (bậc lẻ).

### B. Hamiltonian Path / Cycle (Đường đi / Chu trình Hamilton)
* **Rule**: You must visit **every single VERTEX (đỉnh) exactly once**.
* **The Trick**: There is no mathematical trick! It is an NP-Complete problem. 
* **How to solve**: You MUST use **DFS + Backtracking**. If $N$ is small ($\le 10$), standard recursion works. If $N$ is slightly larger ($\le 20$), you must use **Bitmask DP** to avoid TLE.

---

## 5. Advanced Topics (End of the Semester)
As you progress, you will learn to deal with weighted graphs (where roads have distances/costs):
1. **Shortest Path (Đường đi ngắn nhất)**: Finding the fastest route from A to B.
   * *Algorithm*: Dijkstra's Algorithm (uses a Priority Queue).
2. **Minimum Spanning Tree (Cây khung nhỏ nhất)**: Connecting all nodes together using the absolute minimum total wire length.
   * *Algorithms*: Kruskal (uses Disjoint Sets) or Prim.

---

## 💡 Summary: How to approach ANY Graph Problem
1. **Read the constraints**: Is $N$ small ($<20$) or large ($10^5$)? This tells you if you can use heavy recursion or need a smart algorithm.
2. **Choose your structure**: Declare `vector<int> adj[N]` and `bool visited[N]`.
3. **Pick your weapon**: 
   - Need to find a path? -> **DFS**. 
   - Need the shortest path? -> **BFS**.
   - Hamiltonian? -> **Backtracking/Bitmask**.
   - Euler? -> **Degree Counting**.
