#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 100
#define MAX_ENTRIES 100

typedef struct
{
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Item;

typedef enum
{
    ADD,
    UPDATE,
    DELETE,
    READ,
    UNKNOWN
} Command;

typedef Item Inventory[MAX_ENTRIES];

char *getValueViaKey(Inventory *items, int currentIndex, const char *key)
{
    for (int i = 0; i < currentIndex; i++)
    {
        if (strcmp((*items)[i].key, key) == 0)
        {
            return (*items)[i].value;
        }
    }

    return NULL;
}

Command getCommand(const char *command)
{
    if (strcmp(command, "add") == 0)
    {
        return ADD;
    }
    else if (strcmp(command, "update") == 0)
    {
        return UPDATE;
    }
    else if (strcmp(command, "delete") == 0)
    {
        return DELETE;
    }
    else if (strcmp(command, "read") == 0)
    {
        return READ;
    }
    else
    {
        return UNKNOWN;
    }
}

int main()
{
    char commandStr[15];

    int currentIndex = 0;

    Inventory inventory;

    printf("Welcome! Here you can manage your inventory.\n");
    printf("You can either add, update or delete keys. You can also read what's in the inventory.\n");
    printf("Keys can not have spaces in them.\n");
    printf("What would you like to do? (add, update, delete, read): ");
    scanf("%15s", commandStr);

    Command command = getCommand(commandStr);

    switch (command)
    {
    case ADD:
        printf("What key would you like to add? ");
        scanf("%99s", inventory[currentIndex].key);

        printf("\n");

        printf("What value would you like to add? ");
        scanf("%99s", inventory[currentIndex].value);

        printf("\n Successfully added %s with value %s\n", inventory[currentIndex].key, inventory[currentIndex].value);

        currentIndex++;

        break;
    case UPDATE:
        // Code for the update command
        break;
    case DELETE:
        // Code for the delete command
        break;
    case READ:
        printf("Key of item you'd like to read? ");
        char key[MAX_KEY_LENGTH];
        scanf("%99s", key);
        printf("Value: %s\n", getValueViaKey(&inventory, currentIndex, key));
        break;
    case UNKNOWN:
    default:
        printf("Unknown command: %s\n", commandStr);
        break;
    }

    return 0;
}
