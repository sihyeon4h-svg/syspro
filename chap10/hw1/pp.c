#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
}

int pop(struct node **top) {
    if (*top == NULL) return -1;
    struct node *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

void printStack(struct node *top) {
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int main() {
    struct node *top = NULL;
    double input;
    while (1) {
        if (scanf("%lf", &input) != 1) break;
        if (input <= 0) {
            printf("Print stack\n");
            printStack(top);
            break;
        }
        if (input != (int)input) {
            push(&top, (int)input);
            printf("Print stack\n");
            printStack(top);
            break;
        }
        push(&top, (int)input);
    }
    return 0;
}
