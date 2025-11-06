#include <stdio.h>
#include <stdlib.h>

typedef struct Q {
    int data;
    struct Q *next;
} Q;

Q *front = NULL, *rear = NULL;

void enqueue(int x) {
    Q *n = malloc(sizeof(Q));
    n->data = x;
    n->next = NULL;
    if (!rear) front = rear = n;
    else { rear->next = n; rear = n; }
}

void dequeue() {
    if (!front)
        printf("Queue Underflow\n");
    else {
        printf("Dequeued: %d\n", front->data);
        Q *t = front;
        front = front->next;
        if (!front) rear = NULL;
        free(t);
    }
}

void display() {
    if (!front)
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (Q *p = front; p; p = p->next)
            printf("%d ", p->data);
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
