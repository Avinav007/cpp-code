#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */
struct Node* Reverse(struct Node* head,
					int k)
{
	// Create a stack of Node*
	stack<Node*> mystack;
	struct Node* current = head;
	struct Node* prev = NULL;

	while (current != NULL)
	{
		// Terminate the loop whichever
		// comes first either current == NULL
		// or count >= k
		int count = 0;
		while (current != NULL &&
			count < k)
		{
			mystack.push(current);
			current = current->next;
			count++;
		}

		// Now pop the elements of stack
		// one by one
		while (mystack.size() > 0)
		{
			// If final list has not been
			// started yet.
			if (prev == NULL)
			{
				prev = mystack.top();
				head = prev;
				mystack.pop();
			}
			else
			{
				prev->next = mystack.top();
				prev = prev->next;
				mystack.pop();
			}
		}
	}

	// Next of last element will
	// point to NULL.
	prev->next = NULL;

	return head;
}

// UTILITY FUNCTIONS
// Function to push a node
void push(struct Node** head_ref,
		int new_data)
{
	// Allocate node
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	// Put in the data
	new_node->data = new_data;

	// Link the old list off the
	// new node
	new_node->next = (*head_ref);

	// Move the head to point to
	// the new node
	(*head_ref) = new_node;
}

// Function to print linked list
void printList(struct Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

// Driver code
int main(void)
{
	// Start with the empty list
	struct Node* head = NULL;

	// Created Linked list is
	// 1->2->3->4->5->6->7->8->9
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("Given linked list ");
	printList(head);
	head = Reverse(head, 3);

	printf("Reversed Linked list ");
	printList(head);

	return 0;
}
