#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void f(){system("leaks a.out");
}
int main() {
    
    char *line = NULL;
    int fd = open("1char.txt", O_RDONLY);
    atexit(f);
    // line = get_next_line(fd);
    // printf("%s", line);
    // free(line);
    // line = get_next_line(fd);

    // exit(0);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    // line = get_next_line(fd);
    // printf("%s", line);
    // free(line);
    

    // while(line)
    // {
    //     line = get_next_line(fd);
    //     printf("%s", line);
    //     free (line);
    //     line = NULL;
    // }
    // free(line);
    // atexit(f);
    return 0;

}
