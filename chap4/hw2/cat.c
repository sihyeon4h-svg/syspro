#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;
    int line_number = 1;
    int show_line_numbers = 0;
    int i;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        show_line_numbers = 1;
        i = 2;
    } else {
        i = 1;    }

    for (; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) continue;

        if (show_line_numbers)
            printf("%6d  ", line_number++);

        while ((c = getc(fp)) != EOF) {
            putchar(c);
            if (show_line_numbers && c == '\n')
                printf("%6d  ", line_number++);
        }

        fclose(fp);
    }

    return 0;
}


