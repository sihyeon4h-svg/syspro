#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*tail == NULL) {
        *head = newnode;
        *tail = newnode;
    } else {
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

int delete(struct node **head, struct node **tail) {
    if (*head == NULL) return -1;
    struct node *temp = *head;
    int value = temp->data;
    *head = (*head)->next;
    if (*head == NULL) *tail = NULL;
    free(temp);
    return value;
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    char input[20];
    int num;

    while (1) {
        scanf("%s", input);

        int isNumber = 1;
        for (int i = 0; input[i]; i++)
            if (!isdigit(input[i])) isNumber = 0;

        if (!isNumber) break;

        num = atoi(input);
        if (num != 1)
            addq(&head, &tail, num);
    }

    printf("Print queue\n");
    while (head != NULL) {
        printf("%d\n", delete(&head, &tail));
    }

    return 0;
}

