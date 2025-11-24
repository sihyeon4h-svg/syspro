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

int compare(const void *a, const void *b) {
    Book *A = (Book *)a;
    Book *B = (Book *)b;
    if (A->year < B->year) return 1;
    if (A->year > B->year) return -1;
    return 0;
}

int main() {
    FILE *fp;
    Book *arr;
    long fileSize;
    int count;

    fp = fopen("db.dat", "rb");
    if (fp == NULL) return 1;

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);

    count = fileSize / sizeof(Book);
    arr = (Book*)malloc(sizeof(Book) * count);
    if (arr == NULL) {
        fclose(fp);
        return 1;
    }

    fread(arr, sizeof(Book), count, fp);
    fclose(fp);

    qsort(arr, count, sizeof(Book), compare);

    fp = fopen("db.dat", "wb");
    if (fp == NULL) {
        free(arr);
        return 1;
    }

    fwrite(arr, sizeof(Book), count, fp);
    fclose(fp);
    free(arr);

    return 0;
}

