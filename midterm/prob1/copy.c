#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *src, *dst;
    int ch;
    int option;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <option> <source> <destination>\n", argv[0]);
        return 1;
    }

    option = atoi(argv[1]);
    if (option < 0 || option > 2) {
        fprintf(stderr, "Error: option must be 0, 1, or 2\n");
        return 1;
    }

    src = fopen(argv[2], "r");
    if (src == NULL) {
        perror("Error opening source file");
        return 1;
    }

    dst = fopen(argv[3], "w");
    if (dst == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        if (option == 1)
            ch = tolower(ch);
        else if (option == 2)
            ch = toupper(ch);
        fputc(ch, dst);
    }

    fclose(src);
    fclose(dst);

    dst = fopen(argv[3], "r");
    if (dst == NULL) {
        perror("Error reopening destination file");
        return 1;
    }

    printf("결과 (%s 파일 내용): ", argv[3]);
    while ((ch = fgetc(dst)) != EOF)
        putchar(ch);
    printf("\n");

    fclose(dst);
    return 0;
}

