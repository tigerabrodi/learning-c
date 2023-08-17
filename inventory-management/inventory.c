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

char *get_value_by_key(Inventory *items, int current_index, const char *key)
{
    for (int i = 0; i < current_index; i++)
    {
        if (strcmp((*items)[i].key, key) == 0)
        {
            return (*items)[i].value;
        }
    }

    return NULL;
}

void update_value_by_key(Inventory *items, int current_index, const char *key, const char *new_value)
{
    for (int i = 0; i < current_index; i++)
    {
        if (strcmp((*items)[i].key, key) == 0)
        {
            strncpy((*items)[i].value, new_value, MAX_VALUE_LENGTH - 1);

            (*items)[i].value[MAX_VALUE_LENGTH - 1] = '\0'; // Ensure null termination
            printf("Successfully updated %s to %s\n", key, new_value);
            return;
        }
    }

    printf("Could not find key %s\n", key);
}

void delete_value_by_key(Inventory *items, int *current_index, const char *key)
{
    int found_index = -1;

    for (int i = 0; i < *current_index; i++)
    {
        if (strcmp((*items)[i].key, key) == 0)
        {
            found_index = i;
            break;
        }
    }

    if (found_index == -1)
    {
        printf("Could not find key %s\n", key);
        return;
    }

    // Shift all items that come after the deleted one one position to the left, with the first item being the found index to be deleted
    for (int i = found_index; i < *current_index - 1; i++)
    {
        (*items)[i] = (*items)[i + 1];
    }

    (*current_index)--;

    printf("Successfully deleted %s\n", key);
}

Command get_command(const char *command)
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

void print_inventory(const Item *items, int current_index)
{
    printf("Current Inventory:\n");
    for (int i = 0; i < current_index; i++)
    {
        printf("Key: %s, Value: %s\n", items[i].key, items[i].value);
    }
    if (current_index == 0)
    {
        printf("The inventory is empty.\n");
    }
}

int main()
{
    char command_str[20];
    int current_index = 0;
    Inventory inventory;

    printf("Welcome! Here you can manage your inventory.\n");
    printf("You can either add, update, or delete keys. You can also read what's in the inventory or end the program.\n");
    printf("Keys cannot have spaces in them.\n");

    while (1) // Infinite loop to keep accepting commands
    {
        printf("What would you like to do? (add, update, delete, read, end): ");
        scanf("%19s", command_str);

        if (strcmp(command_str, "end") == 0)
        {
            printf("Thank you for using the inventory system!\n");
            print_inventory(inventory, current_index);

            break;
        }

        Command command = get_command(command_str);

        switch (command)
        {
        case ADD:
            printf("What key would you like to add? ");
            scanf("%99s", inventory[current_index].key);

            printf("\n");

            printf("What value would you like to add? ");
            scanf("%99s", inventory[current_index].value);

            printf("\n Successfully added %s with value %s\n", inventory[current_index].key, inventory[current_index].value);

            current_index++;
            break;
        case UPDATE:
            printf("What key would you like to update? ");
            char key_to_update[MAX_KEY_LENGTH];
            scanf("%99s", key_to_update);

            printf("\n");

            char new_value[MAX_VALUE_LENGTH];
            printf("What would you like to update the value to? ");
            scanf("%99s", new_value);

            printf("\n");

            update_value_by_key(&inventory, current_index, key_to_update, new_value);

            break;
        case DELETE:
            printf("What key would you like to delete? ");
            char key_to_delete[MAX_KEY_LENGTH];
            scanf("%99s", key_to_delete);
            delete_value_by_key(&inventory, current_index, key_to_delete);
            break;
        case READ:
            printf("Key of item you'd like to read? ");
            char key[MAX_KEY_LENGTH];
            scanf("%99s", key);
            printf("Value: %s\n", get_value_by_key(&inventory, current_index, key));
            break;
        case READ_INVENTORY:
            print_inventory(inventory, current_index);
            break;
        case UNKNOWN:
        default:
            printf("Unknown command: %s\n", command_str);
            break;
        }
    }

    return 0;
}
