#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = 0, rear = -1, count = 0;

void insertFront(int x) {
    if (count == MAX)
        printf("Deque Overflow\n");
    else {
        front = (front - 1 + MAX) % MAX;
        deque[front] = x;
        count++;
    }
}

void insertRear(int x) {
    if (count == MAX)
        printf("Deque Overflow\n");
    else {
        rear = (rear + 1) % MAX;
        deque[rear] = x;
        count++;
    }
}

void deleteRear() {
    if (count == 0)
        printf("Deque Underflow\n");
    else {
        printf("Deleted (rear): %d\n", deque[rear]);
        rear = (rear - 1 + MAX) % MAX;
        count--;
    }
}

void display() {
    if (count == 0)
        printf("Deque is empty\n");
    else {
        printf("Deque elements: ");
        for (int i = 0; i < count; i++)
            printf("%d ", deque[(front + i) % MAX]);
        printf("\n");
    }
}

int main() {
    int ch, x;
    do {
        printf("\n1.InsertFront 2.InsertRear 3.DeleteRear 4.Display 0.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &x); insertFront(x); break;
            case 2: printf("Enter value: "); scanf("%d", &x); insertRear(x); break;
            case 3: deleteRear(); break;
            case 4: display(); break;
        }
    } while (ch != 0);
}
