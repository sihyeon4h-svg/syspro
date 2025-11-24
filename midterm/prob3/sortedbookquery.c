#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    char author[50];
    int year;
    int numborrow;
    char borrow[10];
} Book;

int compare(const void *a, const void *b) {
    Book *x = (Book*)a;
    Book *y = (Book*)b;
    return y->numborrow - x->numborrow;
}

int main() {
    FILE *fp = fopen("db.dat", "r");
    if (!fp) return 1;

    Book books[MAX];
    int count = 0;

    while (fread(&books[count], sizeof(Book), 1, fp) == 1) {
    count++;
}
    fclose(fp);

    qsort(books, count, sizeof(Book), compare);

    int mode;
    printf("0: list of all books, 1: list of available books ) ");
    scanf("%d", &mode);

    printf("%-3s %-12s %-10s %-6s %-10s %-6s\n",
       "id", "bookname", "author", "year", "numborrow", "borrow");
    for (int i = 0; i < count; i++) {
        if (mode == 1 && strcmp(books[i].borrow, "False") == 0)
            continue;

        printf("%-3d %-12s %-10s %-6d %-10d %-6s\n",
            books[i].id,
            books[i].name,
            books[i].author,
            books[i].year,
            books[i].numborrow,
            books[i].borrow
        );
    }

    return 0;
}
