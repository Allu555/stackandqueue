#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *rear = NULL;

void enqueue(int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    if (!rear) {
        rear = n;
        rear->next = rear;
    } else {
        n->next = rear->next;
        rear->next = n;
        rear = n;
    }
}

void dequeue() {
    if (!rear)
        printf("Queue Underflow\n");
    else {
        Node *front = rear->next;
        printf("Dequeued: %d\n", front->data);
        if (front == rear) rear = NULL;
        else rear->next = front->next;
        free(front);
    }
}

void display() {
    if (!rear)
        printf("Queue is empty\n");
    else {
        Node *p = rear->next;
        printf("Queue elements: ");
        do {
            printf("%d ", p->data);
            p = p->next;
        } while (p != rear->next);
        printf("\n");
    }
}

int main() {
    int ch, x;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 0);
}
