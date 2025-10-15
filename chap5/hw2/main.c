#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd;
    char buf;
    char savedText[100][100];
    int line = 0, col = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("File open error");
        return 1;
    }

    while (read(fd, &buf, 1) > 0) {
        if (buf == '\n') {
            savedText[line][col] = '\0';
            line++;
            col = 0;
        } else {
            savedText[line][col++] = buf;
        }
    }
    savedText[line][col] = '\0';
    close(fd);

    for (int i = line; i >= 0; i--) {
        printf("%s\n", savedText[i]);
    }

    return 0;
}
