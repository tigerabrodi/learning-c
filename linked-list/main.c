#include <stdio.h>
#include <stdlib.h>

// Define the structure for our linked list node.
typedef struct Node
{
	int data;	   // The data the node will hold.
	struct Node *next; // Pointer to the next node in the list.
} Node;

// Function to create a new node with given data.
Node *createNode(int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node.
	if (!newNode)
	{ // Check if memory allocation was successful.
		printf("Memory error\n");
		return NULL;
	}
	newNode->data = data; // Assign data to the node.
	newNode->next = NULL; // Initialize next pointer to NULL.
	return newNode;	      // Return the new node.
}

// Function to append a node to the end of the linked list.
void append(Node **head, int data)
{
	Node *newNode = createNode(data); // Create a new node with the given data.
	if (*head == NULL)
	{			 // If the list is empty,
		*head = newNode; // set the new node as the head.
		return;
	}

	Node *last = *head; // Start at the head of the list.
	while (last->next)
	{ // Traverse till the end of the list.
		last = last->next;
	}
	last->next = newNode; // Make the last node's next point to the new node.
}

// Function to print the linked list.
void printList(Node *head)
{
	Node *curr = head; // Start at the head of the list.
	while (curr)
	{				      // While there are nodes to process.
		printf("%d -> ", curr->data); // Print the current node's data.
		curr = curr->next;	      // Move to the next node.
	}
	printf("NULL\n"); // Print NULL for the end of the list.
}

// Function to free the memory used by the linked list.
void freeList(Node *head)
{
	Node *curr = head; // Start at the head of the list.
	Node *next;	   // Temporary pointer to store the next node.

	while (curr)
	{			   // While there are nodes to process.
		next = curr->next; // Store the next node.
		free(curr);	   // Free the current node.
		curr = next;	   // Move to the next node.
	}
}

int main()
{
	Node *head = NULL; // Initialize the head of the linked list to NULL.

	append(&head, 10); // Append data 10 to the list.
	append(&head, 20); // Append data 20 to the list.
	append(&head, 30); // Append data 30 to the list.

	printList(head); // Print the entire list.

	freeList(head); // Free the memory occupied by the list.

	return 0; // Return 0 to indicate successful completion.
}
