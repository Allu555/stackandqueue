#include <stdio.h>
#define MAX 100

char queue[MAX];
int front = 0, rear = -1, count = 0;

void enqueue(char c) {
    if (count == MAX)
        printf("Queue Overflow\n");
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = c;
        count++;
    }
}

void dequeue() {
    if (count == 0)
        printf("Queue Underflow\n");
    else {
        printf("Dequeued: %c\n", queue[front]);
        front = (front + 1) % MAX;
        count--;
    }
}

void display() {
    if (count == 0)
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (int i = 0; i < count; i++)
            printf("%c ", queue[(front + i) % MAX]);
        printf("\n");
    }
}

int main() {
    int ch;
    char c;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter character: "); scanf(" %c", &c); enqueue(c); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 0);
}
