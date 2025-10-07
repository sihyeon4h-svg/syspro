#include <stdio.h>
#include <string.h>

#define MAXLINE 100
#define MAXINPUT 5

void swap(char arr[][MAXLINE], int i, int j);

int main() {
    char lines[MAXINPUT][MAXLINE];
    int lengths[MAXINPUT];
    int i, j;

    for (i = 0; i < MAXINPUT; i++) {
        fgets(lines[i], MAXLINE, stdin);
        lines[i][strcspn(lines[i], "\n")] = '\0';
        lengths[i] = strlen(lines[i]);
    }

    for (i = 0; i < MAXINPUT - 1; i++) {
        for (j = i + 1; j < MAXINPUT; j++) {
            if (lengths[i] < lengths[j]) {
                int temp = lengths[i];
                lengths[i] = lengths[j];
                lengths[j] = temp;
                swap(lines, i, j);
            }
        }
    }

    for (i = 0; i < MAXINPUT; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}

void swap(char arr[][MAXLINE], int i, int j) {
    char temp[MAXLINE];
    strcpy(temp, arr[i]);
    strcpy(arr[i], arr[j]);
    strcpy(arr[j], temp);
}

