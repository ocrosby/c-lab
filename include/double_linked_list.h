#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct DNode {
    void *data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode* create_dnode(void *data);
void insert_dnode(DNode **head, DNode *node_to_insert);
void delete_dnode(DNode **head, DNode *node_to_delete);
void* search_dnode(DNode *head, void *data_to_find);
void free_dlist(DNode *head);

#endif /* DOUBLE_LINKED_LIST_H */