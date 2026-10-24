
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> tasks;
    vector<bool> completed;

    int choice;

    do {
        cout << "\n===== TO-DO LIST APP =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string task;
            cout << "Enter task: ";
            getline(cin >> ws, task);

            tasks.push_back(task);
            completed.push_back(false);

            cout << "Task added successfully!\n";
        }
        else if (choice == 2) {
            if (tasks.empty()) {
                cout << "No tasks available.\n";
            } else {
                cout << "\nYour Tasks:\n";

                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". "
                         << (completed[i] ? "[Completed] " : "[Pending] ")
                         << tasks[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            int taskNo;
            cout << "Enter task number to complete: ";
            cin >> taskNo;

            if (taskNo >= 1 && taskNo <= tasks.size()) {
                completed[taskNo - 1] = true;
                cout << "Task marked as completed!\n";
            } else {
                cout << "Invalid task number!\n";
            }
        }
        else if (choice == 4) {
            int taskNo;
            cout << "Enter task number to delete: ";
            cin >> taskNo;

            if (taskNo >= 1 && taskNo <= tasks.size()) {
                tasks.erase(tasks.begin() + taskNo - 1);
                completed.erase(completed.begin() + taskNo - 1);
                cout << "Task deleted successfully!\n";
            } else {
                cout << "Invalid task number!\n";
            }
        }
        else if (choice == 5) {
            cout << "Exiting To-Do List App. Goodbye!\n";
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
