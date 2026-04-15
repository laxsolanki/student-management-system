# 🎓 Student Management System (Qt + C)

## 📌 Description

This project is a **Student Management System** built using **Qt (GUI) and C**.
It allows users to manage student records through a graphical interface with proper validation and file handling.

The project demonstrates integration of **C backend logic** with a **Qt-based GUI**, making it a practical example of combining low-level programming with modern UI.

---

## 🚀 Features

* ➕ Add Student with validation
* 🔍 Search Student (by name or roll number)
* ✏️ Update Student details
* ❌ Delete Student record
* 📋 View all students in table format
* 🔐 Login system (admin authentication)
* 🔄 Refresh form inputs

---

## 🛠️ Technologies Used

* **C** → Core logic & file handling
* **C++ (Qt Framework)** → GUI development
* **Qt Widgets** → UI components
* **CMake** → Build system

---

## 🧠 How It Works

* All student data is stored in a file: `student.txt`
* Data is saved in CSV format:

  ```
  Name,Roll,Father,Mother,Class,Batch
  ```
* Operations like **add, search, update, delete** are performed using file handling in C
* Qt GUI interacts with C functions using `extern "C"`

---

## 🔐 Login Credentials

```
Username: admin
Password: 1007
```

---

## 📂 Project Structure

```
StudentApp/
│
├── main.cpp
├── mainwindow.cpp / .h / .ui
├── login.cpp / .h / .ui
├── student.c / student.h
├── CMakeLists.txt
└── student.txt
```

---

## ⚙️ Build & Run

### 🔹 Using Qt Creator

1. Open project folder
2. Load `CMakeLists.txt`
3. Configure kit (MinGW / MSVC)
4. Build & Run

---


## ⭐ Future Improvements

* Add database (SQLite/MySQL)
* Improve UI design
* Add user roles (admin/user)
* Export data to CSV/Excel

---
