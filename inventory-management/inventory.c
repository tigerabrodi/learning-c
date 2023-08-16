#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 100
#define MAX_ENTRIES 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Item;

typedef Item Inventory[MAX_ENTRIES]; // Define Inventory as an array of Items

// Function to find the value for a given key
char* findValue(Inventory* items, int currentIndex, const char* key) {
    for (int i = 0; i < currentIndex; i++) {
        if (strcmp((*items)[i].key, key) == 0) {
            return (*items)[i].value;
        }
    }
    return NULL; // Return NULL if key not found
}

int main()
{
   char command[MAX_KEY_LENGTH]; // Increased the size to avoid buffer overflow

   int currentIndex = 0;

   Inventory inventory;

   printf("Welcome! Here you can manage your inventory.\n");

   printf("You can either add, update or delete keys. You can also read what's in the inventory.\n");

   printf("Keys can not have spaces in them.\n");

   printf("What would you like to do? (add, update, delete, read): ");

   scanf("%s", command);

   if (strcmp(command, "add") == 0) {
        printf("What key would you like to add? ");
        scanf("%99s", inventory[currentIndex].key);

        printf("What value would you like to add? ");
        scanf("%99s", inventory[currentIndex].value);

        currentIndex++;
   }

   if (strcmp(command, "read") == 0) {
        printf("Key of item you'd like to read? ");
        char key[MAX_KEY_LENGTH];
        scanf("%99s", key);
        printf("Value: %s\n", findValue(&inventory, currentIndex, key));
   }

   return 0;
}
