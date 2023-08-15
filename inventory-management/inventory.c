#include <stdio.h>
#include <string.h>

struct Item {
    char *key;
    char *value;
};

int main()
{
   char command[] = "add";

   struct Item inventory;

   printf("Welcome! Here you can manage your inventory.\n");

   printf("You can either add, update or delete keys. You can also read what's in the inventory.\n");

   printf("Keys can not have spaces in them.\n");

   printf("What would you like to do? (add, update, delete, read): ");

   scanf("%s", command);

   if (command == "add") {
	char key[100];
	char value[200];
	printf("What key would you like to add? ");
	scanf("%s", key);

	printf("What value would you like to add? ");
	scanf("%s", value);

	// Add key and value to inventory
	inventory.key = key;
	inventory.value = value;
   }
}