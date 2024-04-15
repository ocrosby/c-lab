#include <stdlib.h>
#include "linked_list.h"

Node* create_node(void *data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL; // Failed to allocate memory
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node **head, Node *node_to_insert) {
    if (head == NULL || node_to_insert == NULL) {
        return; // Invalid parameters
    }
    node_to_insert->next = *head;
    *head = node_to_insert;
}

void delete_node(Node **head, Node *node_to_delete) {
    if (head == NULL || *head == NULL || node_to_delete == NULL) {
        return; // Invalid parameters
    }
    if (*head == node_to_delete) {
        *head = node_to_delete->next;
    } else {
        Node *current = *head;
        while (current->next != NULL && current->next != node_to_delete) {
            current = current->next;
        }
        if (current->next == node_to_delete) {
            current->next = node_to_delete->next;
        }
    }
    free(node_to_delete->data);
    free(node_to_delete);
}

void* search_node(Node *head, void *data_to_find) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == data_to_find) {
            return current->data;
        }
        current = current->next;
    }
    return NULL; // Not found
}

void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}
