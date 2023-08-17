#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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