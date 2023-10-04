#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char description[100];
    int isCompleted;
};

void addTask(struct Task tasks[], int* taskCount, const char* description)
{
    if (*taskCount < 100)
    {
        struct Task newTask;
        strcpy(newTask.description, description);
        newTask.isCompleted = 0; // Initialize as not completed
        tasks[*taskCount] = newTask;
        (*taskCount)++;
    }
    else
    {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

void markAsCompleted(struct Task tasks[], int taskCount, int taskIndex)
{
    if (taskIndex >= 0 && taskIndex < taskCount)
    {
        tasks[taskIndex].isCompleted = 1;
        printf("Task marked as completed.\n");
    }
    else
    {
        printf("Invalid task index.\n");
    }
}

void deleteTask(struct Task tasks[], int* taskCount, int taskIndex)
{
    if (taskIndex >= 0 && taskIndex < *taskCount)
    {
        for (int i = taskIndex; i < *taskCount - 1; i++)
        {
            tasks[i] = tasks[i + 1];
        }
        (*taskCount)--;
        printf("Task deleted successfully.\n");
    }
    else
    {
        printf("Invalid task index.\n");
    }
}

void displayTasks(struct Task tasks[], int taskCount, int showCompleted)
{
    printf("\nTo-Do List\n");
    for (int i=0; i<taskCount; i++)
    {
        if (showCompleted || !tasks[i].isCompleted)
        {
            printf("%d. %s [%s]\n", i + 1, tasks[i].description, tasks[i].isCompleted ? "Completed" : "Not Completed");
        }
    }
}

int main()
{
    struct Task tasks[100];
    int taskCount = 0;

    while (1)
    {
        printf("1. Add Task\n");
        printf("2. Mark Completed\n");
        printf("3. Delete Completed Task\n");
        printf("4. Show All\n");
        printf("5. Show Pending\n");
        printf("6. Show Completed\n");
        printf("7. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter task description: ");
                char description[100];
                scanf(" %[^\n]", description);
                addTask(tasks, &taskCount, description);
                break;
            case 2:
                printf("Enter task index to mark as completed: ");
                int markIndex;
                scanf("%d", &markIndex);
                markAsCompleted(tasks, taskCount, markIndex - 1);
                break;
            case 3:
                printf("Enter task index to delete: ");
                int deleteIndex;
                scanf("%d", &deleteIndex);
                deleteTask(tasks, &taskCount, deleteIndex - 1);
                break;
            case 4:
                displayTasks(tasks, taskCount, 1); // Show all tasks
                break;
            case 5:
                displayTasks(tasks, taskCount, 0); // Show incomplete tasks
                break;
            case 6:
                displayTasks(tasks, taskCount, 1); // Show completed tasks
                break;
            case 7:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid\n");
        }
    }

    return 0;
}