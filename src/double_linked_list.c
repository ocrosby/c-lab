#include <stdlib.h>
#include "double_linked_list.h"

DNode* create_dnode(void *data) {
    DNode *new_node = (DNode*)malloc(sizeof(DNode));
    if (new_node == NULL) {
        return NULL; // Failed to allocate memory
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_dnode(DNode **head, DNode *node_to_insert) {
    if (head == NULL || node_to_insert == NULL) {
        return; // Invalid parameters
    }
    node_to_insert->next = *head;
    if (*head != NULL) {
        (*head)->prev = node_to_insert;
    }
    *head = node_to_insert;
}

void delete_dnode(DNode **head, DNode *node_to_delete) {
    if (head == NULL || *head == NULL || node_to_delete == NULL) {
        return; // Invalid parameters
    }
    if (node_to_delete->prev != NULL) {
        node_to_delete->prev->next = node_to_delete->next;
    } else {
        *head = node_to_delete->next;
    }
    if (node_to_delete->next != NULL) {
        node_to_delete->next->prev = node_to_delete->prev;
    }
    free(node_to_delete->data);
    free(node_to_delete);
}

void* search_dnode(DNode *head, void *data_to_find) {
    DNode *current = head;
    while (current != NULL) {
        if (current->data == data_to_find) {
            return current->data;
        }
        current = current->next;
    }
    return NULL; // Not found
}

void free_dlist(DNode *head) {
    DNode *current = head;
    while (current != NULL) {
        DNode *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}