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