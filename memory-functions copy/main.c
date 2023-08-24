#include <stdio.h>
#include <unistd.h> // For sbrk()

// Define a block header structure
typedef struct BlockHeader
{
	size_t size;		  // Size of the block
	struct BlockHeader *next; // Pointer to the next block (useful for coalescing)
	int is_free;		  // Indicates whether the block is free or not
} BlockHeader;

// Keep track of the first block
BlockHeader *first_block = NULL;

// Prototype for our custom malloc function
void *my_malloc(size_t size);

// Prototype for our custom free function
void my_free(void *ptr);

int main()
{
	// Test the my_malloc function
	int *arr = (int *)my_malloc(10 * sizeof(int));

	// Check if allocation was successful
	if (!arr)
	{
		printf("Memory allocation failed!\n");
		return 1;
	}

	// Use the allocated memory
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i * 10;
		printf("%d ", arr[i]);
	}
	printf("\n");

	// Free the allocated memory
	my_free(arr);

	return 0;
}

void *my_malloc(size_t size)
{
	// 1. Adjust size for metadata and alignment. Initialize a free list if it doesn't exist.

	// Hint: Aligning memory involves ensuring that the allocated block starts
	// on an address that’s a multiple of some power of two. Here's a basic
	// way to align to 8 bytes: `(size + 7) & ~7`.

	// First, ensure the size aligns to 8 bytes for general memory use efficiency.
	size = (size + 7) & ~7;

	// Now, add the size of the block header to account for metadata.
	size += sizeof(BlockHeader);

	// At this point, the size variable holds the total amount of memory you need:
	// the adjusted request + space for your block header.

	// ... Rest of your function will be developed in subsequent steps.
}
