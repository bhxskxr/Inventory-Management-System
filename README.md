# Inventory Management System (C++)

A dynamic Inventory Management System built using C++ and Data Structures concepts. This project simulates an inventory store where you can add, modify, delete, buy, and manage products in memory with the ability to store data in files.

## 🛠 Features
- Add, modify, delete products
- View current session inventory
- Save/load inventory to/from files
- Buy products with billing and 5% discount
- Linked list structure for dynamic memory use

## ⚙️ Technologies
- C++ (Procedural)
- Singly Linked List
- File Handling (text files)
- Windows.h for animations and UI

## 🧠 DSA Concepts Used

- **Singly Linked List:**  
  Used to store products dynamically. Nodes represent products with ID, name, price, and quantity.
  
- **Pointers and Dynamic Memory Allocation:**  
  New product entries are dynamically created and linked.

- **Search and Modify Operations:**  
  Traverse the list to find and update or delete nodes.

- **File Handling:**  
  Products are saved to and read from text files.

## 📂 File Structure
- `Inventory_Management_CompletelyFixed.cpp`: Main source file
- `billrecord.txt`: Generated billing record
- `Products_Record.txt`: Saved product data

## 🚀 How to Run
```bash
g++ Inventory_Management_CompletelyFixed.cpp -o inventory
./inventory
