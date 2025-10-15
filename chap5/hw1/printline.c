#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd;
    char buf;
    char savedText[100][100];
    int line = 0, col = 0;
    char input[50];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("File open error");
        return 1;
    }

    while (read(fd, &buf, 1) > 0) {
        if (buf == '\n') {
            savedText[line][col] = '\0';
            line++;
            col = 0;
        } else {
            savedText[line][col++] = buf;
        }
    }
    savedText[line][col] = '\0';
    close(fd);

    printf("File read success\n");
    printf("Total Line : %d\n", line + 1);
    printf("You can choose 1 ~ %d Line\n", line + 1);
    printf("Pls 'Enter' the line to select : ");
    scanf("%s", input);

    if (strcmp(input, "*") == 0) {
        for (int i = 0; i <= line; i++) {
            printf("%s\n", savedText[i]);
        }
    } else if (strchr(input, '-') != NULL) {
        int start, end;
        sscanf(input, "%d-%d", &start, &end);
        for (int i = start - 1; i < end && i <= line; i++) {
            printf("%s\n", savedText[i]);
        }
    } else if (strchr(input, ',') != NULL) {
        char *token = strtok(input, ",");
        while (token != NULL) {
            int n = atoi(token);
            if (n >= 1 && n <= line + 1)
                printf("%s\n", savedText[n - 1]);
            token = strtok(NULL, ",");
        }
    } else {
        int n = atoi(input);
        if (n >= 1 && n <= line + 1)
            printf("%s\n", savedText[n - 1]);
        else
            printf("Invalid line number.\n");
    }

    return 0;
}
