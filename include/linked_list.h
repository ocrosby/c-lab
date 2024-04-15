#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

Node* create_node(void *data);
void insert_node(Node **head, Node *node_to_insert);
void delete_node(Node **head, Node *node_to_delete);
void* search_node(Node *head, void *data_to_find);
void free_list(Node *head);

#endif /* LINKED_LIST_H */