#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char author[30];
    int year;
    int numBorrow;
    int borrowed; // 0: 대출 가능, 1: 대출 중
} Book;

int main() {
    FILE *fp = fopen("bookdata.dat", "wb");
    if (fp == NULL) {
        printf("파일 생성 실패\n");
        return 1;
    }

    int n;
    printf("등록할 책의 개수를 입력하세요: ");
    scanf("%d", &n);
    getchar(); // 개행문자 제거

    Book book;
    for (int i = 0; i < n; i++) {
        printf("\n[%d번째 책 정보 입력]\n", i + 1);
        book.id = i + 1;

        printf("책 이름: ");
        fgets(book.name, sizeof(book.name), stdin);
        book.name[strcspn(book.name, "\n")] = '\0'; // 개행 제거

        printf("저자 이름: ");
        fgets(book.author, sizeof(book.author), stdin);
        book.author[strcspn(book.author, "\n")] = '\0';

        printf("출판년도: ");
        scanf("%d", &book.year);

        printf("대출 횟수: ");
        scanf("%d", &book.numBorrow);

        printf("대출 여부(0: True, 1: False): ");
        scanf("%d", &book.borrowed);
        getchar(); // 개행 제거

        fwrite(&book, sizeof(Book), 1, fp);
    }

    fclose(fp);
    printf("\n모든 책 정보가 bookdata.dat 파일에 저장되었습니다.\n");
    return 0;
}

