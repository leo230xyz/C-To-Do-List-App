#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class ToDoList
{
private:
    int List_Size = 0;
    int TasksCount;
    int AchievedTasksCount;
    string Tasks[50];
    bool MarkedTasks[50]; // Boolean array to mark tasks as achieved

public:
    // Function to input tasks from user
    void InPutTasks()
    {
        cout << "---------------------------------------" << endl;
        cout << "Entering Your Tasks Section: " << endl;
        cout << "Enter Your To-Do List Size: ";
        cin >> List_Size;
        for (int i = 0; i < List_Size; i++)
        {
            cout << "Enter Task " << i + 1 << " : ";
            cin >> Tasks[i];
            MarkedTasks[i] = false;  // Initialize all tasks as not marked
        }
    }

    int AchievedCount;

    // Function to mark tasks as achieved
    void AddAchievedTask()
    {
        cout << "---------------------------------------" << endl;
        cout << "Entering Your Achieved Tasks Section: " << endl;
        cout << "How Many Tasks Do You Want to Mark As Achieved? (0 to skip): ";
        int AchievedCount;
        cin >> AchievedCount;

        if (AchievedCount > 0)
        {
            for (int i = 0; i < AchievedCount; i++)
            {
                int taskIndex;
                cout << "Enter the Task Index (1 - " << List_Size << ") to mark as achieved: ";
                cin >> taskIndex;

                // Validate index range
                if (taskIndex <= 0 || taskIndex > List_Size)
                {
                    cout << "Invalid index. Please enter a value between 1 and " << List_Size << endl;
                    continue;
                }

                // Mark the task as achieved
                MarkedTasks[taskIndex - 1] = true; // Adjust for 0-based indexing
            }
            cout << AchievedCount << " task(s) marked as achieved." << endl;
        }
        else
        {
            cout << "Skipping achievement marking." << endl;
        }
    }

    // Function to output tasks to a file
    void OutPutTasks()
    {
        ofstream File;
        File.open("D:\\t4.txt");

        cout << "---------------------------------------" << endl;
        cout << "Your Tasks Are: " << endl;
        File << "Your Tasks Are: " << endl;
        for (int i = 0; i < List_Size; i++)
        {
            cout << "Task No " << i + 1 << " Is: " << Tasks[i] << endl;
            File << "Task No " << i + 1 << " Is: " << Tasks[i] << endl;
        }
        cout << "---------------" << endl;
        File << "-----------------" << endl;

        cout << "List Status: " << endl;
        File << "List Status: " << endl;

        cout << "Tasks Count: " << List_Size << endl;
        File << "Tasks Count: " << List_Size << endl;

        // Print Achieved Tasks
        cout << "\nMarked Tasks (Achieved):" << endl;
        File << "\nMarked Tasks (Achieved):" << endl;
        bool anyAchieved = false;
        for (int i = 0; i < List_Size; i++)
        {
            if (MarkedTasks[i])
            {
                cout << "Task No " << i + 1 << ": " << Tasks[i] << endl;
                File << "Task No " << i + 1 << ": " << Tasks[i] << endl;
                anyAchieved = true;
            }
        }
        if (!anyAchieved)
        {
            cout << "None!" << endl;
            File << "None!" << endl;
        }

        // Print Unachieved Tasks
        cout << "\nNot Marked Tasks (Not Achieved):" << endl;
        File << "\nNot Marked Tasks (Not Achieved):" << endl;
        bool anyUnachieved = false;
        for (int i = 0; i < List_Size; i++)
        {
            if (!MarkedTasks[i])
            {
                cout << "Task No " << i + 1 << ": " << Tasks[i] << endl;
                File << "Task No " << i + 1 << ": " << Tasks[i] << endl;
                anyUnachieved = true;
            }
        }
        if (!anyUnachieved)
        {
            cout << "None!" << endl;
            File << "None!" << endl;
        }
    }

    // Function to add new tasks to the existing list
    void AddToExistTask()
    {
        int NewTask;
        cout << "---------------------------------------" << endl;
        cout << "Entering New Tasks Section: " << endl;
        cout << "How Many New Tasks Do You Want To Add? ";
        cin >> NewTask;

        for (int i = List_Size; i < List_Size + NewTask; i++)
        {
            cout << "Enter Your New Task No " << i - List_Size + 1 << " : ";
            cin >> Tasks[i];
            MarkedTasks[i] = false;  // Initialize new tasks as not marked
        }

        List_Size += NewTask; // Update the total task count
        cout << "\nNew Task(s) Have Been Added!" << endl;
    }
};

int main()
{
    ToDoList t;
    int choice = 0;

    cout << "Main Menu For The To Do List APP !!" << endl;

    while (choice != 5)
    {
        cout << "---------------------------------------" << endl;
        cout << "Press 1 To Input Your Tasks. " << endl
            << "Press 2 To Mark Your Achieved Tasks. " << endl
            << "Press 3 To Update/Add New Tasks To Your List " << endl
            << "Press 4 To Output Your Tasks " << endl
            << "Press 5 To Quit." << endl
            << "Select Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.InPutTasks();
            break;
        case 2:
            t.AddAchievedTask();
            break;
        case 3:
            t.AddToExistTask();
            break;
        case 4:
            t.OutPutTasks();
            break;
        case 5:
            break;
        default:
            cout << "Invalid Input. Choose Between 1 - 5!!" << endl;
            break;
        }
    }
}
