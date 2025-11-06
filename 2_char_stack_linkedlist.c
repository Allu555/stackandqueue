#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char c;
    struct Node *next;
} Node;

Node *top = NULL;

void push(char c) {
    Node *n = malloc(sizeof(Node));
    n->c = c;
    n->next = top;
    top = n;
}

void pop() {
    if (!top)
        printf("Stack Underflow\n");
    else {
        printf("Popped: %c\n", top->c);
        Node *t = top;
        top = top->next;
        free(t);
    }
}

void display() {
    if (!top)
        printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        for (Node *p = top; p; p = p->next)
            printf("%c ", p->c);
        printf("\n");
    }
}

int main() {
    int ch;
    char c;
    do {
        printf("\n1.Push 2.Pop 3.Display 0.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter character: "); scanf(" %c", &c); push(c); break;
            case 2: pop(); break;
            case 3: display(); break;
        }
    } while (ch != 0);
}
