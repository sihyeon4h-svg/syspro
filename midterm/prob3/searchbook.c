#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char author[50];
    int year;
    int numborrow;
    char borrow[10];
} Book;

int main() {
    FILE *fp;
    Book b;
    char target[50];
    int found = 0;

    fp = fopen("db.dat", "rb");
    if (fp == NULL) {
        printf("cannot open db.dat file\n");
        return 1;
    }

    printf("input name of book ) ");
    scanf("%s", target);
 
    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (strcmp(b.name, target) == 0) {
            found = 1;
            printf("%-3s %-12s %-10s %-6s %-10s %-6s\n", 
                "id", "bookname", "author", "year", "numborrow", "borrow");
            printf("%-3d %-12s %-10s %-6d %-10d %-6s\n",
                   b.id, b.name, b.author, b.year, b.numborrow, b.borrow);
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\nnot found book name : '%s'\n", target);
    }

    return 0;
}

