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
    int mode, target;
    scanf("%d %d", &mode, &target);

    FILE *fp = fopen("db.dat", "rb+");
    if (!fp) return 0;

    Book b;

    printf("0 bookId: borrow book, 1 bookId: return book ) %d %d\n", mode, target);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == target) {
            if (mode == 0) {
                if (strcmp(b.borrow, "False") == 0) {
                    b.numborrow++;
                    strcpy(b.borrow, "True");
                    printf("You've got bellow book..\n");
                } else {
                    printf("You cannot borrow bellow book since it has been booked.\n");
                }
            } else if (mode == 1) {
                if (strcmp(b.borrow, "True") == 0) {
                    strcpy(b.borrow, "False");
                    printf("You've returned bellow book..\n");
                } else {
                    printf("This book is not currently borrowed.\n");
                }
            }

            fseek(fp, -sizeof(Book), SEEK_CUR);
            fwrite(&b, sizeof(Book), 1, fp);

            printf("%d %s %s %d %d %s\n",
                   b.id, b.name, b.author, b.year, b.numborrow, b.borrow);
            break;
        }
    }

    fclose(fp);
    return 0;
}
