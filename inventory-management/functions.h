#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"

char *get_value_by_key(Inventory *items, int current_index, const char *key);
void update_value_by_key(Inventory *items, int current_index, const char *key, const char *new_value);
void delete_value_by_key(Inventory *items, int *current_index, const char *key);
void print_inventory(const Item *items, int current_index);
Command get_command(const char *command);

#endif
