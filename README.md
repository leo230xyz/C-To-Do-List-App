# To-Do List Application (C++)

## 📋 Description

This project is a simple **console-based To-Do List application** built in C++. It allows users to manage their daily tasks efficiently by adding, marking, and tracking tasks. The app also outputs task details to a file for external reference.

---

## ✨ Features

* **Input Tasks**: Users can add tasks to their to-do list.
* **Mark Achieved Tasks**: Easily mark tasks as completed.
* **Add New Tasks**: Expand your task list by appending new tasks.
* **Output Tasks**: Export your task list to a file (`t4.txt`) with details of achieved and unachieved tasks.
* **File Support**: Outputs all tasks and their status to a text file for easy reference.

---

## 🛠️ How It Works

1. **Menu Options**:

   * `1`: Input tasks to create a new to-do list.
   * `2`: Mark specific tasks as achieved.
   * `3`: Add new tasks to the existing list.
   * `4`: Output the task list to the console and a file.
   * `5`: Exit the application.

2. **Data Storage**:

   * Tasks are stored in an array (`Tasks[]`).
   * Task completion is tracked using a boolean array (`MarkedTasks[]`).
   * The data is written to `D:\t4.txt` when outputting tasks.

3. **Validation**:

   * Ensures valid input for task indices.
   * Prevents exceeding the task list size limit of 50.

---

## 🚀 How to Run the Code

1. **Prerequisites**:

   * A C++ compiler (e.g., GCC, Clang, or Visual Studio).

2. **Compile the Code**:

   ```bash
   g++ -o ToDoListApp ToDoListApp.cpp
   ```

3. **Run the Application**:

   ```bash
   ./ToDoListApp
   ```

4. Follow the on-screen menu to interact with the app.

---

## 📂 Output File

The app writes all tasks and their statuses to a file named `t4.txt` located in `D:\`. Ensure this directory exists on your system before running the application to avoid file errors.

---

## 📌 Limitations

* **Task List Limit**: Supports a maximum of 50 tasks.
* **No Persistent Storage**: Tasks are not saved after the program is closed unless exported.
* **Static File Path**: The output file path is hardcoded as `D:\t4.txt`.

---

## 🛠️ Future Enhancements

* Add dynamic file path support.
* Implement persistent storage with external databases or files.
* Create a graphical user interface (GUI) for easier usage.

---

## 📄 License

This project is open-source and free to use. Feel free to contribute or modify as needed.

---

### 💡 Author

Built with ❤️ in C++ for task management enthusiasts.
