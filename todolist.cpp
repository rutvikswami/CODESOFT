#include <iostream>
#include <string>
using namespace std;

const int MAXTASKS = 100;

class Task {
public:
    string description;
    bool completed;

    Task() : completed(false) {}
};

class TodoList {
private:
    Task tasks[MAXTASKS];
    int taskCount;

public:
    TodoList() : taskCount(0) {}
    
    void addTask(const string& task) {
        if (taskCount < MAXTASKS) {
            tasks[taskCount].description = task;
            cout << "Task added: " << task << endl;
            taskCount++;
        } else {
            cout << "Task list is full!" << endl;
        }
    }

    void viewTasks() {
        if (taskCount == 0) {
            cout << "No tasks in the list." << endl;
            return;
        }
        cout << "Your tasks:" << endl;
        for (int i = 0; i < taskCount; i++) {
            cout << i + 1 << " " << tasks[i].description << ". [" << (tasks[i].completed ? "X" : " ") << "] "<<endl;
        }
    }

    void markTaskCompleted(int index) {
        if (index < 1 || index > taskCount) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[index - 1].completed = true;
        cout << "Task marked as completed: " << tasks[index - 1].description << endl;
    }

    void deleteTask(int index) {
        if (index < 1 || index > taskCount) {
            cout << "Invalid task number." << endl;
            return;
        }
        cout << "Deleting task: " << tasks[index - 1].description << endl;
        for (int i = index - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];  // Shift tasks left
        }
        taskCount--;
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); 

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                getline(cin, task);//getline() to take a line a text as input 
                todoList.addTask(task);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int tasknumber;
                cout << "Enter the task number to mark as completed: ";
                cin >> tasknumber;
                todoList.markTaskCompleted(tasknumber);
                break;
            }
            case 4: {
                int taskNumber;
                cout << "Enter the task number to delete: ";
                cin >> taskNumber;
                todoList.deleteTask(taskNumber);
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
