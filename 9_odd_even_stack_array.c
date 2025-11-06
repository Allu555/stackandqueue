#include <stdio.h>
#define MAX 100

int src[MAX], topS = -1;
int odd[MAX], topO = -1;
int even_[MAX], topE = -1;

void push(int stack[], int *top, int x) {
    if (*top == MAX - 1)
        printf("Overflow\n");
    else
        stack[++(*top)] = x;
}

int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Underflow\n");
        return -1;
    } else
        return stack[(*top)--];
}

int isEmpty(int top) {
    return top == -1;
}

int main() {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &x);
        push(src, &topS, x);
    }

    while (!isEmpty(topS)) {
        int val = pop(src, &topS);
        if (val % 2 == 0)
            push(even_, &topE, val);
        else
            push(odd, &topO, val);
    }

    printf("\nEven stack (top->bottom): ");
    for (int i = topE; i >= 0; i--)
        printf("%d ", even_[i]);
    printf("\nOdd stack (top->bottom): ");
    for (int i = topO; i >= 0; i--)
        printf("%d ", odd[i]);
    printf("\n");
}
