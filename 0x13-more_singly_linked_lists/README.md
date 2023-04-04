## Linked List Project

This project includes several functions related to linked lists, written in C programming language. The listint_t data structure is used in this project to represent singly linked lists.

### listint_t Structure

c
Copy code
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
This structure contains an integer value and a pointer to the next node.

### Functions

The functions implemented in this project are:

print_listint - Prints all the elements of a listint_t list and returns the number of nodes.
listint_len - Returns the number of elements in a linked listint_t list.
add_nodeint - Adds a new node at the beginning of a listint_t list and returns the address of the new element.
free_listint - Frees a listint_t list.
free_listint2 - Frees a listint_t list and sets the head to NULL.
pop_listint - Deletes the head node of a listint_t linked list and returns the head node's data (n).
get_nodeint_at_index - Returns the nth node of a listint_t linked list.
sum_listint - Returns the sum of all the data (n) of a listint_t linked list.
insert_nodeint_at_index - Inserts a new node at a given position.
delete_nodeint_at_index - Deletes the node at index index of a listint_t linked list.
reverse_listint - Reverses a listint_t linked list.
print_listint_safe - Prints a listint_t linked list safely (can print lists with a loop).
free_listint_safe - Frees a listint_t list safely (can free lists with a loop).
find_listint_loop - Finds the loop in a linked list.


This project is created by Aishat Adewoyin.
