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
    FILE *fp = fopen("db.dat", "ab");
    if (!fp) return 0;

    Book b;
    int bval;

    while (scanf("%d %s %s %d %d %d",
                 &b.id, b.name, b.author,
                 &b.year, &b.numborrow, &bval) != EOF) {

        if (bval == 0) strcpy(b.borrow, "False");
        else strcpy(b.borrow, "True");

        fwrite(&b, sizeof(Book), 1, fp);
    }

    fclose(fp);
    return 0;
}
