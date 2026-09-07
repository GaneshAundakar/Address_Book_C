# Address Book Management System

A highly modular, performance-focused Command Line Interface (CLI) application engineered in Standard C. This project demonstrates system-level programming fundamentals, low-level memory architecture control, and persistent data manipulation without relying on external third-party database engines.

---

## 🚀 Key Features

* **Persistent Database Engine:** Implements a custom file handler to read, write, parse, and synchronize application states directly to a local disk format (CSV), ensuring data survival across runtime cycles.
* **Full CRUD Functionality:** Supports seamless contact addition, real-time lookups, dynamic updates, and record removal.
* **Advanced Search Filters:** Features multi-criteria search algorithms allowing users to query contacts instantaneously by name, phone number, or email address.
* **Robust Input Sanitization:** Integrated strict conditional validation loops to intercept and block malformed data entries (e.g., telephone length constraints and email structural syntax checks).
* **Modular Codebase:** Decoupled design architecture isolating user interface loops, logical evaluations, and persistent disk-writing drivers.

---

## 🧠 Technical Concepts

* **Structures (`struct`):** Encapsulates diverse primitive data types into cohesive record shapes to minimize overhead and handle relational contact data efficiently.
* **File Streams & I/O Handling:** Demonstrates complete control over stream buffers via `fopen`, `fprintf`, `fscanf`, and `fclose` with precise file-existence checking and validation layers.
* **Pointers & Pass-by-Reference:** Maximizes runtime performance and reduces stack memory utilization by passing references rather than duplicating large data records across scope barriers.
* **String Manipulation Layouts:** Utilizes string handling patterns (`<string.h>`) to clean, filter whitespace, and dynamically evaluate nested contact parameters.
* **Defensive Error Handling:** Protects application execution flows against buffer overflows, invalid menu options, and empty or corrupted data files.

---

## 📐 Project Architecture & Data Flow

The architecture is explicitly decoupled into independent compilation modules to uphold software engineering best practices.

```text
+-----------------------------------------------------------+
|                      USER INTERFACE                       |
|                          Main.c                           |
|  - Manages execution menu loop                            |
|  - Captures terminal keyboard input                       |
|  - Triggers frontend interface responses                  |
+-----------------------------+-----------------------------+
                              |
                              v  (Function Calls / Menu Choices)
+-----------------------------------------------------------+
|                    CORE BUSINESS LOGIC                    |
|                   contact.c / contact.h                   |
|  - Add Contact (Create)      - Search Contacts (Read)     |
|  - Edit Contact (Update)     - Delete Contact (Delete)    |
|  - Performs validation logic on structural strings        |
+-----------------------------+-----------------------------+
                              |
                              v  (Passes Structure Arrays / Records)
+-----------------------------------------------------------+
|                   DATA PERSISTENCE LAYER                  |
|                       file.c / file.h                     |
|  - Save Contacts to Disk (File Write Operations)          |
|  - Load Contacts from Disk (File Read & Parsing Engine)   |
+-----------------------------+-----------------------------+
                              |
                              v  (Standard File I/O Streams)
+-----------------------------------------------------------+
|                      HARDWARE STORAGE                     |
|                        contacts.csv                       |
|  - Permanent flat-file text storage on hard disk          |
+-----------------------------------------------------------+
```

### File Manifest

```text
.
├── Main.c          # Application entry point and top-level user execution loop
├── contact.c       # Core implementation of CRUD and contact indexing operations
├── contact.h       # Global structural outlines, macros, and function prototypes
├── file.c          # Persistent disk synchronization routines (Save/Load engines)
├── file.h          # File system constants and I/O function mapping definitions
└── contacts.csv    # Local persistent flat-file database storage
```

---

## 🛠️ How to Build and Run Locally

Ensure you have a standard C compiler (such as `gcc`) installed on your system terminal.

1. **Clone the repository:**
   ```bash
   git clone https://github.com/GaneshAundakar/address_book_c.git
   cd address_book_c
   ```

2. **Compile the modular source files together:**
   ```bash
   gcc main.c contact.c file.c -o address_book_app
   ```

3. **Execute the compiled native binary:**
   ```bash
   ./address_book_app
   ```

---

## 📈 Future System Expansions

* **Hardware Migration:** Adapting the underlying text parsing engines into an Embedded C context for microcontrollers driving physical interfaces.
* **Advanced Sorting Algorithms:** Integrating customized QuickSort or MergeSort routines to sort massive datasets instantly by diverse fields.

---
