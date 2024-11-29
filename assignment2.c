#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int id;
    char name[45];
    int age;
} User;

void InputBuffer()
{
    int c;
    while ((c=getchar())!='\n'&&c!=EOF);
}

int isValidInteger(int num)
{
    return num > 0;
}

int isUniqueID(int id)
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        return 1;
    }

    User user;
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age)!=EOF)
    {
        if (user.id==id)
        {
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 1;
}

void createUser()
{
    FILE *file = fopen("users.txt", "a+");

    if (file == NULL)
    {
        printf("Error opening the file\n");
        return;
    }



    User user;
    printf("Enter ID: ");
    if (scanf("%d", &user.id) != 1 || !isValidInteger(user.id))
    {
        printf("Please enter a positive integer\n");
        InputBuffer();
        fclose(file);
        return;
    }

    if (!isUniqueID(user.id))
    {
        printf("ID already exists. It needs to be unique.\n");
        InputBuffer();
        fclose(file);
        return;
    }

    printf("Enter name: ");
    scanf("%s", user.name);
    printf("Enter age: ");
    if (scanf("%d", &user.age) != 1 || !isValidInteger(user.age))
    {
        printf("Please enter a valid age\n");
        InputBuffer();
        fclose(file);
        return;
    }

    fprintf(file, "%d %s %d\n", user.id, user.name, user.age);
    fclose(file);
}

void readUsers()
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("File does not exist\n");
        return;
    }

    User user;
    bool empty = true;
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF)
    {
        empty = false;
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }
    if (empty) printf("No users exist\n");
    fclose(file);
}

void updateUser()
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("File does not exist\n");
        return;
    }

    User user;
    int id;
    int found = 0;
    printf("Enter ID to update: ");

    if (scanf("%d", &id) != 1 || !isValidInteger(id))
    {
        printf("Please enter positive integer.\n");
        InputBuffer();
        fclose(file);
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == id)
        {
            found = 1;
            printf("Enter new Name: ");
            scanf("%s", user.name);
            printf("Enter new Age: ");
            if (scanf("%d", &user.age) != 1 || !isValidInteger(user.age))
            {
                printf("Please enter a valid age\n");
                InputBuffer();
                fclose(file);
                fclose(tempFile);
                remove("temp.txt");
                return;
            }
        }
        fprintf(tempFile, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found)
    {
        printf("User updated\n");
    }
    else
    {
        printf("User not found\n");
    }
}

void deleteUser()
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("File does not exist\n");
        return;
    }

    User user;
    //bool empty = true;
    int id, found = 0;
    printf("Enter ID: ");
    if (scanf("%d", &id) != 1 || !isValidInteger(id))
    {
        printf("Please enter positive integer\n");
        InputBuffer();
        fclose(file);
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id != id)
        {

            fprintf(tempFile, "%d %s %d\n", user.id, user.name, user.age);
        }
        else
        {
            found = 1;
        }
    }


    fclose(file);
    fclose(tempFile);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found)
    {
        printf("User deleted successfully\n");
    }
    else
    {
        printf("User not found\n");
    }
}

int main()
{
    int ch;

    while (1)
    {
        printf("1. Create User\n2. Read Users\n3. Update User\n4. Delete User\n5. Exit\n\n");
        printf("Enter your choice: ");
        if (scanf("%d", &ch) != 1)
        {
            printf("Please enter a valid choice.\n");
            InputBuffer();
            continue;
        }

        switch (ch)
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
                exit(0);
            default:
                printf("Please enter a valid choice\n");
        }
    }

    return 0;
}
