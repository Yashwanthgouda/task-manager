# Task Manager

This is a simple task manager application written in Python. It allows users to create, manage, and organize tasks with various features such as setting priorities, adding labels, and attaching files.

## Features

- **Add Task**: Create new tasks with title, description, due date, and priority.
- **Delete Task**: Remove tasks by their unique ID.
- **Update Task Status**: Change the status of tasks (e.g., Pending, Completed).
- **Search Tasks**: Search for tasks using keywords.
- **View Tasks**: Display all tasks with their details.
- **Export Tasks**: Export tasks to a file.
- **Import Tasks**: Import tasks from a file.
- **Add Subtask**: Add subtasks to a main task.
- **Assign Task**: Assign tasks to users.
- **Add Label**: Add labels to tasks.
- **Add Attachment**: Add attachments to tasks.

## Technologies Used

- **Programming Language**: Python
- **Libraries**: `uuid`, `datetime`

## How to Run

1. **Clone the Repository**
   ```bash
   git clone https://github.com/Yashwanthgouda/task-manager.git
   cd task-manager
2. Run the Program
   ```bash
   python task_manager.py


here’s an example output of how the task management system would function:
Task Manager Output:
Task Manager
1. Add Task
2. Delete Task
3. Update Task Status
4. Search Tasks
5. View Tasks
6. Export Tasks
7. Import Tasks
8. Quit
Enter your choice: 1

Enter task title: Complete Assignment
Enter task description: Finish the math assignment by tomorrow
Enter due date (DD-MM-YYYY): 06-08-2024
Enter priority (Low/Medium/High): High
Task added successfully!

Task Manager
1. Add Task
2. Delete Task
3. Update Task Status
4. Search Tasks
5. View Tasks
6. Export Tasks
7. Import Tasks
8. Quit
Enter your choice: 5

Tasks:
Title: Complete Assignment
Description: Finish the math assignment by tomorrow
Due Date: 06-08-2024
Priority: High
Status: Pending
Subtasks: 
Assigned To: None
Labels: 
Attachments: 

Task Manager
1. Add Task
2. Delete Task
3. Update Task Status
4. Search Tasks
5. View Tasks
6. Export Tasks
7. Import Tasks
8. Quit
Enter your choice: 3

Enter task ID to update status: 1a2b3c4d
Enter new status: Completed
Task status updated successfully!

Task Manager
1. Add Task
2. Delete Task
3. Update Task Status
4. Search Tasks
5. View Tasks
6. Export Tasks
7. Import Tasks
8. Quit
Enter your choice: 5

Tasks:
Title: Complete Assignment
Description: Finish the math assignment by tomorrow
Due Date: 06-08-2024
Priority: High
Status: Completed
Subtasks: 
Assigned To: None
Labels: 
Attachments: 

Task Manager
1. Add Task
2. Delete Task
3. Update Task Status
4. Search Tasks
5. View Tasks
6. Export Tasks
7. Import Tasks
8. Quit
Enter your choice: 8

Goodbye!


Usage
Add Task: Follow the prompts to add a new task.
Delete Task: Remove an existing task by specifying its ID.
Update Task Status: Modify the status of a task by specifying its ID.
Search Tasks: Search for tasks containing specific keywords.
View Tasks: Display all tasks with their details.
Export Tasks: Export all tasks to a specified file.
Import Tasks: Import tasks from a specified file.
License
This project is licensed under the MIT License. See the LICENSE file for details.

Contributing
Contributions are welcome! Please fork the repository and submit a pull request for any enhancements or bug fixes.

Acknowledgments
This project was developed as part of a learning exercise in Python programming.
Special thanks to the open-source community for providing resources and support.
