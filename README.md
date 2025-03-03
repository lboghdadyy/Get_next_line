# Get Next Line

## Description
Get Next Line (GNL) is a 42 school project that involves writing a function to read a line from a file descriptor efficiently. The function should handle reading from different file descriptors, work with a specified buffer size, and return one line at a time.

## Function Prototype
```c
char *get_next_line(int fd);
```
- Reads from file descriptor `fd`.
- Returns the next line from the file, including the newline (`\n`) if present.
- Returns `NULL` when the end of the file is reached or in case of an error.

## Features
- Works with any file descriptor (`stdin`, files, sockets, etc.).
- Manages multiple file descriptors simultaneously.
- Uses a static buffer to store leftover characters for efficient reading.
- Handles variable-length lines correctly.

## Compilation
To compile with `get_next_line`, use:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o GNL
```
You can adjust the `BUFFER_SIZE` as needed.

## Usage
### Example in C
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## Edge Cases Handled
- Works with any `BUFFER_SIZE` (though optimal sizes improve performance).
- Handles empty files correctly.
- Manages memory allocation efficiently to avoid leaks.
- Supports reading from multiple file descriptors simultaneously.
  
## Author
Soufiane Baghdadi
