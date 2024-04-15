#include <stdlib.h>
#include "queue.h"

Queue* create_queue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL; // Failed to allocate memory
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, void *data) {
    if (queue == NULL) {
        return; // Invalid queue
    }
    QueueNode *new_node = (QueueNode*)malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        return; // Failed to allocate memory
    }
    new_node->data = data;
    new_node->next = NULL;
    if (queue->rear != NULL) {
        queue->rear->next = new_node;
    }
    queue->rear = new_node;
    if (queue->front == NULL) {
        queue->front = new_node;
    }
}

void* dequeue(Queue *queue) {
    if (queue == NULL || queue->front == NULL) {
        return NULL; // Invalid queue or empty queue
    }
    QueueNode *node_to_dequeue = queue->front;
    void *data = node_to_dequeue->data;
    queue->front = node_to_dequeue->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(node_to_dequeue);
    return data;
}

void* peek(Queue *queue) {
    if (queue == NULL || queue->front == NULL) {
        return NULL; // Invalid queue or empty queue
    }
    return queue->front->data;
}

void free_queue(Queue *queue) {
    if (queue == NULL) {
        return; // Invalid queue
    }
    QueueNode *current = queue->front;
    while (current != NULL) {
        QueueNode *next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}
