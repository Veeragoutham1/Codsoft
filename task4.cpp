/*Build a simple console-based to-do list
manager that allows users to add, view, and
delete tasks
 Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or
pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list.*/

// I have not used namespace std which is standard form to be practical

#include <iostream>
#include <vector>

struct Task
{
    std::string description;
    bool completed;

    Task(const std::string &desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(std::vector<Task> &taskList, const std::string &description)
{
    taskList.push_back(Task(description));
    std::cout << "Task added: " << description << std::endl;
}

// Function to view tasks with their status
void viewTasks(const std::vector<Task> &taskList)
{
    std::cout << "Task List:" << std::endl;
    for (size_t i = 0; i < taskList.size(); i++)
    {
        std::cout << i + 1 << ". ";
        if (taskList[i].completed)
        {
            std::cout << "[X] ";
        }
        else
        {
            std::cout << "[ ] ";
        }
        std::cout << taskList[i].description << std::endl;
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(std::vector<Task> &taskList, size_t index)
{
    if (index >= 0 && index < taskList.size())
    {
        taskList[index].completed = true;
        std::cout << "Task marked as completed: " << taskList[index].description << std::endl;
    }
    else
    {
        std::cout << "Invalid task index." << std::endl;
    }
}

// Function to remove a task from the list
void removeTask(std::vector<Task> &taskList, size_t index)
{
    if (index >= 0 && index < taskList.size())
    {
        std::cout << "Task removed: " << taskList[index].description << std::endl;
        taskList.erase(taskList.begin() + index);
    }
    else
    {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main()
{
    std::vector<Task> taskList;

    while (true)
    {
        std::cout << "To-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            std::cin.ignore(); // Clear the newline character from the buffer
            std::cout << "Enter the task description: ";
            std::string description;
            std::getline(std::cin, description);
            addTask(taskList, description);
        }
        else if (choice == 2)
        {
            viewTasks(taskList);
        }
        else if (choice == 3)
        {
            viewTasks(taskList);
            std::cout << "Enter the index of the task to mark as completed: ";
            size_t index;
            std::cin >> index;
            markTaskAsCompleted(taskList, index - 1); // Adjust for 0-based indexing
        }
        else if (choice == 4)
        {
            viewTasks(taskList);
            std::cout << "Enter the index of the task to remove: ";
            size_t index;
            std::cin >> index;
            removeTask(taskList, index - 1); // Adjust for 0-based indexing
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    std::cout << "Thank you for using the To-Do List Manager!" << std::endl;

    return 0;
}
