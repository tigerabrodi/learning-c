#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

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
            fgets(inventory[current_index].value, MAX_VALUE_LENGTH, stdin);

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
            fgets(new_value, MAX_VALUE_LENGTH, stdin);

            printf("\n");

            update_value_by_key(&inventory, current_index, key_to_update, new_value);

            break;
        case DELETE:
            printf("What key would you like to delete? ");
            char key_to_delete[MAX_KEY_LENGTH];
            scanf("%99s", key_to_delete);
            delete_value_by_key(&inventory, &current_index, key_to_delete);
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
