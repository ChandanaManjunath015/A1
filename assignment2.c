#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct
{
    int userId;
    char userName[45];
    int userAge;
} User;

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool isValidPositiveInteger(int num)
{
    return num > 0;
}

bool isUniqueUserId(int userId)
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        return true;
    }
    User user;
    bool isUnique = true;
    while (fscanf(file, "%d %s %d", &user.userId, user.userName, &user.userAge) != EOF)
    {
        if (user.userId == userId)
        {
            isUnique = false;
            break;
        }
    }
    fclose(file);
    return isUnique;
}

void createUser()
{
    FILE *file = fopen("users.txt", "a+");
    if (file == NULL)
    {
        printf("Error: Unable to open the file.\n");
        return;
    }
    User user;
    bool validInput = true;
    printf("Enter User ID(positive integer): ");
    if (scanf("%d", &user.userId) != 1 || !isValidPositiveInteger(user.userId))
    {
        printf("Error: Please enter a valid positive integer.\n");
        validInput = false;
    }
    else if (!isUniqueUserId(user.userId))
    {
        printf("Error: User ID already exists. It must be unique.\n");
        validInput = false;
    }
    if (!validInput)
    {
        clearInputBuffer();
        fclose(file);
        return;
    }
    printf("Enter User Name: ");
    scanf("%s", user.userName);
    printf("Enter User Age: ");
    if (scanf("%d", &user.userAge) != 1 || !isValidPositiveInteger(user.userAge))
    {
        printf("Error: Please enter a valid age.\n");
        clearInputBuffer();
        fclose(file);
        return;
    }
    fprintf(file, "%d %s %d\n", user.userId, user.userName, user.userAge);
    printf("User created successfully.\n");
    fclose(file);
}

void readUsers()
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("No users exist.\n");
        return;
    }
    User user;
    bool isEmpty = true;
    while (fscanf(file, "%d %s %d", &user.userId, user.userName, &user.userAge) != EOF)
    {
        isEmpty = false;
        printf("ID: %d, Name: %s, Age: %d\n", user.userId, user.userName, user.userAge);
    }
    if (isEmpty)
    {
        printf("No users exist.\n");
    }
    fclose(file);
}

void updateUser()
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("No users exist.\n");
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        printf("Error: Unable to create a temporary file.\n");
        fclose(file);
        return;
    }
    User user;
    int userId;
    bool userFound = false;
    printf("Enter User ID to update: ");
    if (scanf("%d", &userId) != 1 || !isValidPositiveInteger(userId))
    {
        printf("Error: Please enter a valid positive integer.\n");
        clearInputBuffer();
        fclose(file);
        fclose(tempFile);
        remove("temp.txt");
        return;
    }
    while (fscanf(file, "%d %s %d", &user.userId, user.userName, &user.userAge) != EOF)
    {
        if (user.userId == userId)
        {
            userFound = true;
            printf("Enter new User Name: ");
            scanf("%s", user.userName);
            printf("Enter new User Age: ");
            if (scanf("%d", &user.userAge) != 1 || !isValidPositiveInteger(user.userAge))
            {
                printf("Error: Please enter a valid age.\n");
                clearInputBuffer();
                fclose(file);
                fclose(tempFile);
                remove("temp.txt");
                return;
            }
        }
        fprintf(tempFile, "%d %s %d\n", user.userId, user.userName, user.userAge);
    }
    fclose(file);
    fclose(tempFile);
    remove("users.txt");
    rename("temp.txt", "users.txt");
    if (userFound)
    {
        printf("User updated successfully.\n");
    }
    else
    {
        printf("Error: User not found.\n");
    }
}

void deleteUser()
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("No users exist.\n");
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        printf("Error: Unable to create a temporary file.\n");
        fclose(file);
        return;
    }
    User user;
    int userId;
    bool userFound = false;
    printf("Enter User ID to delete: ");
    if (scanf("%d", &userId) != 1 || !isValidPositiveInteger(userId))
    {
        printf("Error: Please enter a valid positive integer.\n");
        clearInputBuffer();
        fclose(file);
        fclose(tempFile);
        remove("temp.txt");
        return;
    }
    while (fscanf(file, "%d %s %d", &user.userId, user.userName, &user.userAge) != EOF)
    {
        if (user.userId != userId)
        {
            fprintf(tempFile, "%d %s %d\n", user.userId, user.userName, user.userAge);
        }
        else
        {
            userFound = true;
        }
    }
    fclose(file);
    fclose(tempFile);
    remove("users.txt");
    rename("temp.txt", "users.txt");
    if (userFound)
    {
        printf("User deleted successfully.\n");
    }
    else
    {
        printf("Error: User not found.\n");
    }
}

int main()
{
    int choice;
    while (true)
    {
        printf("\n1. Create User\n2. Read Users\n3. Update User\n4. Delete User\n5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Error: Please enter a valid choice.\n");
            clearInputBuffer();
            continue;
        }
        switch (choice)
        {
            case 1:
                createUser();
                break;
            case 2:
                readUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Error: Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
