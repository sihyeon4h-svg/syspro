#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char author[50];
    int year;
    int numborrow;
    char borrow[10];
} Book;

int main() {
    int mode;
    scanf("%d", &mode);

    FILE *fp = fopen("db.dat", "rb");
    if (!fp) return 0;

    Book b;

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (mode == 1 && strcmp(b.borrow, "True") != 0) continue;

        printf("%d %s %s %d %d %s\n",
               b.id, b.name, b.author,
               b.year, b.numborrow, b.borrow);
    }

    fclose(fp);
    return 0;
}
