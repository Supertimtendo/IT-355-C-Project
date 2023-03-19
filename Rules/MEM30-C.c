/**
 * @file MEM30-C.c
 * @author Trevor Murphy
 * @brief MEM30-C Do not access freed memory.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;

} Node;

// Function to add a new node to the end of the list
void add_node(Node** head_ref, int data) {
    // Allocate memory for the new node
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty, set the new node as the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse the list to find the end and add the new node
    Node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}


// Function to print the contents of the list
void print_list(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){

    // Create an empty list
    Node* head = NULL;

    // Add nodes to the list
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    
    // Free the memory used by the nodes
    while (head != NULL) {
        Node* next_node = head->next;
        free(head);
        head = next_node;
    }
    
    return 0;
}