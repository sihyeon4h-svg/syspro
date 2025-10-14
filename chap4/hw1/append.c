// append.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *src = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "a");
    int ch;

    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    fclose(src);
    fclose(dest);
    return 0;
}

