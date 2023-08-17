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
    READ_INVENTORY,
    UNKNOWN
} Command;

typedef Item Inventory[MAX_ENTRIES];

char *getValueByKey(Inventory *items, int currentIndex, const char *key)
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
    else if (strcmp(command, "read-inventory") == 0)
    {
        return READ_INVENTORY;
    }
    else
    {
        return UNKNOWN;
    }
}

void printInventory(const Item *items, int currentIndex)
{
    printf("Current Inventory:\n");
    for (int i = 0; i < currentIndex; i++)
    {
        printf("Key: %s, Value: %s\n", items[i].key, items[i].value);
    }
    if (currentIndex == 0)
    {
        printf("The inventory is empty.\n");
    }
}

int main()
{
    char commandStr[20];
    int currentIndex = 0;
    Inventory inventory;

    printf("Welcome! Here you can manage your inventory.\n");
    printf("You can either add, update, or delete keys. You can also read what's in the inventory or end the program.\n");
    printf("Keys cannot have spaces in them.\n");

    while (1) // Infinite loop to keep accepting commands
    {
        printf("What would you like to do? (add, update, delete, read, end): ");
        scanf("%19s", commandStr);

        if (strcmp(commandStr, "end") == 0)
        {
            printf("Thank you for using the inventory system!\n");

            break;
        }

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
            printf("Value: %s\n", getValueByKey(&inventory, currentIndex, key));
            break;
        case READ_INVENTORY:
            printInventory(inventory, currentIndex);
            break;
        case UNKNOWN:
        default:
            printf("Unknown command: %s\n", commandStr);
            break;
        }
    }

    return 0;
}
