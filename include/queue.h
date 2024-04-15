#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    void *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue* create_queue();
void enqueue(Queue *queue, void *data);
void* dequeue(Queue *queue);
void* peek(Queue *queue);
void free_queue(Queue *queue);

#endif /* QUEUE_H */