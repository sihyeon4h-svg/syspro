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
    FILE *fp = fopen("bookdata.dat", "rb");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int option;
    printf("0: list of all books, 1: list of available books ) ");
    scanf("%d", &option);

    Book book;
    printf("id\tbookname\tauthor\tyear\tnumofborrow\tborrow\n");

    while (fread(&book, sizeof(Book), 1, fp)) {
        if (option == 1 && book.borrowed == 1)
            continue; // 대출 중인 책 제외
        printf("%d\t%s\t%s\t%d\t%d\t%s\n",
               book.id, book.name, book.author,
               book.year, book.numBorrow,
               book.borrowed ? "True" : "False");
    }

    fclose(fp);
    return 0;
}

