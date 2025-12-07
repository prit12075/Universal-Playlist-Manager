# 🎵 Neon Playlist Manager (DSA Visualizer)

A **Doubly Linked List** visualization built with **HTML5, CSS3, and JavaScript**.
This project transforms abstract Data Structures into an interactive, animated "Cyberpunk" styled interface, allowing users to see exactly how memory and pointers work in real-time.

## 🚀 Features
- **Visual Memory Management:** Nodes are displayed as cards with simulated memory addresses (e.g., `0x4A1`).
- **Interactive Operations:**
  - **Insert Head/Tail:** Dynamically adds nodes with "Pop-in" animations.
  - **Delete:** Removes nodes and updates pointers instantly.
  - **Reverse:** Visualizes the classic algorithmic reversal of a Doubly Linked List.
- **Glassmorphism UI:** Modern, translucent design using CSS backdrop filters.
- **Pointer Visualization:** Arrows indicate the `next` and `prev` links between nodes.

---

## 🛠️ Tech Stack
- **Frontend:** HTML5, CSS3 (Flexbox, Animations, Variables)
- **Logic:** JavaScript (ES6+ Classes)
- **Icons:** FontAwesome

---

## 🧠 Data Structures & Complexity
Even though this is a web app, the underlying logic follows strict DSA principles.

| Operation | Algorithm Used | Time Complexity |
|-----------|----------------|-----------------|
| **Insert Head/Tail** | Pointer Manipulation | $O(1)$ |
| **Delete Head** | Pointer Update | $O(1)$ |
| **Reverse** | Iterative Swap | $O(N)$ |
| **DOM Rendering** | Linear Traversal | $O(N)$ |

---

## 💻 How to Run
### Option 1: Local Execution
1. Download the repository.
2. Locate `index.html`.
3. Double-click to open it in any modern web browser (Chrome, Safari, Edge).

### Option 2: Live Demo (GitHub Pages)
*(You can enable this in your repo settings!)*
[Link to your Live Project]

---

## 📸 Project Preview
The interface features a "Neon/Night" theme where:
1.  **Nodes** hold the Song Name and a Hexadecimal Address.
2.  **Arrows** represent the `next` and `prev` pointers.
3.  **The Console** at the bottom logs operations (e.g., *"> Inserted 'Levitating' at Tail"*).

---

## 👨‍💻 Author
**Preet Patel**
* Computer Science Engineering Student
* SRM University AP