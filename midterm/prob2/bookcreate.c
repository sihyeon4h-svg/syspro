#include <stdio.h>
#include "bookdate.h"
int main(int argc, char* argv[])
{
    struct bookdate rec;
    FILE *fp;
    if (argc != 2) {
        fprintf(stderr, "How to use: %s FileName\n", argv[0]);
        return 1;
    }
    fp = fopen(argv[1], "w");
    printf("%2s %8s %8s %4s %11s %6s\n", "id", "bookname", "author", "year", "numofborrow", "borrow");
    while (scanf("%d %s %s %d %d %s", &rec.id, rec.bookname, rec.author, &rec.year, &rec.numofborrow, rec.borrow) == 6)
	    fprintf(fp, "%d %s %s %d %d %s", rec.id, rec.bookname, rec.author, rec.year, rec.numofborrow, rec.borrow);
 fclose(fp);
 return 0;
}

