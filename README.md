# 🎵 Universal Playlist Manager

A **Doubly Linked List** implementation in C++ that simulates a music playlist.
This project demonstrates mastery of dynamic memory management, pointer manipulation, and algorithmic efficiency.

## 🚀 Features
- **Dynamic Insertion:** Add songs to the end (Queue behavior) or the beginning (Priority/Stack behavior).
- **Bi-Directional Traversal:** Navigate the playlist forward and backward.
- **Manipulation:** Remove songs by value and reverse the entire playlist.
- **Cycle Detection:** Implements **Floyd’s Cycle-Finding Algorithm** to detect infinite loops.
- **Generic Design:** Uses C++ Templates (`template <typename T>`) to handle any data type (Songs, IDs, etc.).

---

## 🛠️ Data Structures & Complexity
| Operation | Algorithm Used | Time Complexity | Space Complexity |
|-----------|----------------|-----------------|------------------|
| **Insert Head/Tail** | Pointer Manipulation | $O(1)$ | $O(1)$ |
| **Search/Delete** | Linear Search | $O(N)$ | $O(1)$ |
| **Reverse** | Iterative Swap | $O(N)$ | $O(1)$ |
| **Cycle Detect** | Floyd's (Tortoise & Hare) | $O(N)$ | $O(1)$ |

---

## 💻 How to Run
### Prerequisites
- A C++ Compiler (g++, clang, or MSVC)

### Compilation & Execution
**For Mac/Linux:**
```bash
g++ main.cpp -o playlist
./playlist

--- 🎵 LINKED LIST MUSIC PLAYER 🎵 ---
1. Add Song (to End)
2. Add Priority Song (to Start)
3. Remove Song
4. Show Playlist (Forward)
5. Show Playlist (Backward)
6. Reverse Playlist
7. Check for Infinite Loop (Cycle)
0. Exit
Enter choice: 1
Enter song name: Blinding Lights

--- 🎵 LINKED LIST MUSIC PLAYER 🎵 ---
... [Menu options] ...
Enter choice: 1
Enter song name: Levitating

--- 🎵 LINKED LIST MUSIC PLAYER 🎵 ---
... [Menu options] ...
Enter choice: 2
Enter song name: Bohemian Rhapsody
(Added as priority!)

--- 🎵 LINKED LIST MUSIC PLAYER 🎵 ---
... [Menu options] ...
Enter choice: 4
Playlist (Start -> End): [Bohemian Rhapsody] <-> [Blinding Lights] <-> [Levitating] <-> NULL

--- 🎵 LINKED LIST MUSIC PLAYER 🎵 ---
... [Menu options] ...
Enter choice: 6
Playlist reversed successfully!

--- 🎵 LINKED LIST MUSIC PLAYER 🎵 ---
... [Menu options] ...
Enter choice: 4
Playlist (Start -> End): [Levitating] <-> [Blinding Lights] <-> [Bohemian Rhapsody] <-> NULL

--- 🎵 LINKED LIST MUSIC PLAYER 🎵 ---
... [Menu options] ...
Enter choice: 7
No Cycle. Linear Playlist.