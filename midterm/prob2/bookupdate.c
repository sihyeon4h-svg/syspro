#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char author[30];
    int year;
    int numBorrow;
    int borrowed;
} Book;

int main() {
    FILE *fp = fopen("bookdata.dat", "r+b");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int mode, id;
    printf("0 bookId: borrow book, 1 bookId: return book ) ");
    scanf("%d %d", &mode, &id);

    Book book;
    int found = 0;

    while (fread(&book, sizeof(Book), 1, fp)) {
        if (book.id == id) {
            found = 1;
            fseek(fp, -sizeof(Book), SEEK_CUR);

            if (mode == 0) { // 대출
                if (book.borrowed == 1) {
                    printf("'%s' 책은 이미 대출 중입니다.\n", book.name);
                } else {
                    book.numBorrow++;
                    book.borrowed = 1;
                    fwrite(&book, sizeof(Book), 1, fp);
                    printf("'%s'이(가) 대출되었습니다. (대출 횟수 %d)\n",
                           book.name, book.numBorrow);
                }
            } else if (mode == 1) { // 반납
                if (book.borrowed == 0) {
                    printf("'%s' 책은 이미 반납된 상태입니다.\n", book.name);
                } else {
                    book.borrowed = 0;
                    fwrite(&book, sizeof(Book), 1, fp);
                    printf("'%s'이(가) 반납되었습니다.\n", book.name);
                }
            }
            break;
        }
    }

    if (!found) {
        printf("해당 ID의 책을 찾을 수 없습니다.\n");
    }

    fclose(fp);
    return 0;
}

