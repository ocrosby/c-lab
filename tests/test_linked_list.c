#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"

/*
 * This test verifies that if the create_node
 * function is called with a NULL data pointer then
 * a new node is created with a NULL data pointer.
 */
void test_create_node_null() {
    void *data;
    Node *new_node;

    printf("Running test: test_create_node_null\n");

    // Arrange
    data = NULL;

    // Act
    new_node = create_node(data);

    // Assert
    assert(new_node != NULL); // verify that the new_node was allocated successfully
    assert(new_node->data == NULL); // verify that the data property of the new node is NULL
    assert(new_node->next == NULL); // verify that the next pointer is initially NULL

    // Cleanup
    free(new_node);

    printf("Finished test: test_create_node_null\n");
}
