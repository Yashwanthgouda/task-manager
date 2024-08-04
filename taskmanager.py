import uuid
from datetime import datetime

class Task:
    def __init__(self, title, description, due_date, priority):
        self.id = str(uuid.uuid4())
        self.title = title
        self.description = description
        self.due_date = datetime.strptime(due_date, '%d-%m-%Y')
        self.priority = priority
        self.status = "Pending"
        self.subtasks = []
        self.assigned_to = None
        self.labels = []
        self.attachments = []

class TaskManager:
    def __init__(self):
        self.tasks = []

    def add_task(self, task):
        self.tasks.append(task)

    def delete_task(self, task_id):
        self.tasks = [task for task in self.tasks if task.id != task_id]

    def update_task_status(self, task_id, new_status):
        for task in self.tasks:
            if task.id == task_id:
                task.status = new_status

    def get_tasks_due_today(self):
        today = datetime.now().date()
        return [task for task in self.tasks if task.due_date.date() == today]

    def search_tasks(self, keyword):
        return [task for task in self.tasks if keyword.lower() in task.title.lower() or keyword.lower() in task.description.lower()]

    def add_subtask(self, task_id, subtask):
        for task in self.tasks:
            if task.id == task_id:
                task.subtasks.append(subtask)

    def assign_task(self, task_id, assigned_to):
        for task in self.tasks:
            if task.id == task_id:
                task.assigned_to = assigned_to

    def add_label(self, task_id, label):
        for task in self.tasks:
            if task.id == task_id:
                task.labels.append(label)

    def add_attachment(self, task_id, attachment):
        for task in self.tasks:
            if task.id == task_id:
                task.attachments.append(attachment)

    def export_tasks(self, filename):
        with open(filename, 'w') as f:
            for task in self.tasks:
                f.write(f"Task ID: {task.id}\n")
                f.write(f"Title: {task.title}\n")
                f.write(f"Description: {task.description}\n")
                f.write(f"Due Date: {task.due_date.strftime('%d-%m-%Y')}\n")
                f.write(f"Priority: {task.priority}\n")
                f.write(f"Status: {task.status}\n")
                f.write(f"Subtasks: {', '.join([subtask.title for subtask in task.subtasks])}\n")
                f.write(f"Assigned To: {task.assigned_to}\n")
                f.write(f"Labels: {', '.join(task.labels)}\n")
                f.write(f"Attachments: {', '.join(task.attachments)}\n")
                f.write("\n")

    def import_tasks(self, filename):
        with open(filename, 'r') as f:
            task_data = f.read().split("\n\n")
            for task_str in task_data:
                task_info = task_str.split("\n")
                if task_info:
                    task_id = task_info[0].split(": ")[1]
                    title = task_info[1].split(": ")[1]
                    description = task_info[2].split(": ")[1]
                    due_date = datetime.strptime(task_info[3].split(": ")[1], '%d-%m-%Y')
                    priority = task_info[4].split(": ")[1]
                    status = task_info[5].split(": ")[1]
                    subtasks = [subtask.strip() for subtask in task_info[6].split(": ")[1].split(",")]
                    assigned_to = task_info[7].split(": ")[1]
                    labels = [label.strip() for label in task_info[8].split(": ")[1].split(",")]
                    attachments = [attachment.strip() for attachment in task_info[9].split(": ")[1].split(",")]

                    task = Task(title, description, due_date.strftime('%d-%m-%Y'), priority)
                    task.id = task_id
                    task.status = status
                    task.subtasks = [Task(subtask, "", due_date.strftime('%d-%m-%Y'), "") for subtask in subtasks if subtask]
                    task.assigned_to = assigned_to
                    task.labels = labels
                    task.attachments = attachments

                    self.tasks.append(task)

def create_task():
    while True:
        title = input("Enter task title: ")
        description = input("Enter task description: ")
        due_date = input("Enter due date (DD-MM-YYYY): ")
        priority = input("Enter priority (Low/Medium/High): ")

        try:
            due_date = datetime.strptime(due_date, '%d-%m-%Y')
            break
        except ValueError:
            print("Invalid date format. Please enter the date in the format DD-MM-YYYY.")
            continue

    return Task(title, description, due_date.strftime('%d-%m-%Y'), priority)

def main():
    task_manager = TaskManager()

    while True:
        print("\nTask Manager")
        print("1. Add Task")
        print("2. Delete Task")
        print("3. Update Task Status")
        print("4. Search Tasks")
        print("5. View Tasks")
        print("6. Export Tasks")
        print("7. Import Tasks")
        print("8. Quit")

        choice = input("Enter your choice: ")

        if choice == "1":
            task = create_task()
            task_manager.add_task(task)
            print("Task added successfully!")
        elif choice == "2":
            task_id = input("Enter task ID to delete: ")
            task_manager.delete_task(task_id)
            print("Task deleted successfully!")
        elif choice == "3":
            task_id = input("Enter task ID to update status: ")
            new_status = input("Enter new status: ")
            task_manager.update_task_status(task_id, new_status)
            print("Task status updated successfully!")
        elif choice == "4":
            keyword = input("Enter keyword to search tasks: ")
            matching_tasks = task_manager.search_tasks(keyword)
            if matching_tasks:
                print("Matching tasks:")
                for task in matching_tasks:
                    print(task.title)
            else:
                print("No matching tasks found.")
        elif choice == "5":
            print("Tasks:")
            if task_manager.tasks:
                for task in task_manager.tasks:
                    print(f"Title: {task.title}")
                    print(f"Description: {task.description}")
                    print(f"Due Date: {task.due_date.strftime('%d-%m-%Y')}")
                    print(f"Priority: {task.priority}")
                    print(f"Status: {task.status}")
                    print(f"Subtasks: {', '.join([subtask.title for subtask in task.subtasks])}")
                    print(f"Assigned To: {task.assigned_to}")
                    print(f"Labels: {', '.join(task.labels)}")
                    print(f"Attachments: {', '.join(task.attachments)}")
                    print()
            else:
                print("No tasks available.")
        elif choice == "6":
            filename = input("Enter filename to export tasks: ")
            task_manager.export_tasks(filename)
            print("Tasks exported successfully!")
        elif choice == "7":
            filename = input("Enter filename to import tasks: ")
            task_manager.import_tasks(filename)
            print("Tasks imported successfully!")
        elif choice == "8":
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
