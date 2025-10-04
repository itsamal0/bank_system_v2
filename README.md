# Bank Management System v2

A **console-based Bank Management System** written in C++.  

This is **version 2** of my [Bank System](https://github.com/itsamal0/bank_system)
 project, part of my **Learning Path** (Course 8 – Algorithms & Problem Solving Level 4).  
It improves the first version by adding **user login, permission management, and a Manage Users menu**.

You can explore my full Learning Path repository here: [Learning Path Repository](https://github.com/itsamal0/learning-path)

---

## Features (v2)

- Add new clients
- Delete clients  
- Edit existing clients  
- Find clients by account number  
- Deposit and withdraw money  
- Show total balances 
- **New in v2:**  
  - User login system with password authentication  
  - Permission-based access control  
  - Manage Users menu:  
    - List users  
    - Add new user  
    - Delete user  
    - Update user  
    - Find user  

---

## Getting Started

### 1. Clone the repository  
If you have Git installed, run:
```bash
git clone https://github.com/itsamal0/bank_system_v2.git
cd bank_system_v2
```
Or download the project as a ZIP file and extract it.

### 2. Build the project  
Make sure you have a C++ compiler (e.g., g++ or clang) installed. Then build the project:
```bash
g++ src/*.cpp include/helpers/*.cpp -o bank_system_v2
```

### 3. Run the program  
After building successfully, run the program:
```bash
./bank_system_v2
```