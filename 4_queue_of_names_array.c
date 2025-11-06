#include <stdio.h>
#include <string.h>
#define MAX 100
#define LEN 40

char queue[MAX][LEN];
int front = 0, rear = -1, count = 0;

void enqueue(char name[]) {
    if (count == MAX)
        printf("Queue Overflow\n");
    else {
        rear = (rear + 1) % MAX;
        strcpy(queue[rear], name);
        count++;
    }
}

void dequeue() {
    if (count == 0)
        printf("Queue Underflow\n");
    else {
        printf("Dequeued: %s\n", queue[front]);
        front = (front + 1) % MAX;
        count--;
    }
}

void display() {
    if (count == 0)
        printf("Queue is empty\n");
    else {
        printf("Queue elements:\n");
        for (int i = 0; i < count; i++)
            printf("%s\n", queue[(front + i) % MAX]);
    }
}

int main() {
    int ch;
    char name[LEN];
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter name: "); scanf(" %[^\n]", name); enqueue(name); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 0);
}
