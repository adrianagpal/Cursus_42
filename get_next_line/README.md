*This project has been created as part of the 42 curriculum by adrianag.*

# Description
The *get_next_line* project consists of writing a function that reads a file descriptor line by line. Each time the function is called, it should return the next line, ending with the newline character "\n" if it exists. At the end of the file, it will return the remaining part of the line followed by null terminator "\0". The project also manages other situations, such as when the file cannot be read or when the buffer size is 0, and also works correctly with different buffer sizes. 

The project is organized into three files: *get_next_line.c*, which contains the main **get_next_line** function and the core logic for reading lines from a file descriptor; *get_next_line_utils.c*, which contains supporting functions; and *get_next_line.h*, the header file that contains all function prototypes.  

# Instructions

- **Memory management:** Every line returned must be freed by the caller to avoid leaks.

- **Compilation:** To compile the program with a specific buffer size (default is 5) use:
>cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 \<archivos\>.c

- **Example main for testing:**

```
#include "get_next_line.h"

int main(void)
{
    char *new_line;
    int fd;
    
    fd = open("example.txt", O_RDONLY);
    while ((new_line = get_next_line(fd)) != NULL)
    {
       printf("%s", new_line); 
	   free(new_line);
    }    
    if (fd > 0)
    {
        close (fd);    
    }
    return (0);
}
```

# Resources
- https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line
- *man* pages, for functions like read, open and close.
- *Stack Overflow* for general C programming questions and troubleshooting. 

The AI was used to establish a standard for documenting functions with comments. It was also used for theoretical purposes, such as reviewing concepts of pointers, referencing, and dereferencing.

# Algorithm
The logic behind this implementation is that, everytime we read, we keep the information in a static buffer, that is an array. We also set an static index that sets the position in which we are reading from the buffer and static bytes to know how many bytes did we read in the last call. 

These static variables are passed by reference in the **get_next_line** function to build_line function, so their values can be modified. 

**Build_line** function runs a loop continuosly that checks if there is more information to read in the file (**read bytes** function) or there is a new line, which will be returned.  

In the **read_bytes** function, if the static index is 0, it means in the last call, it copied the buffer completely and didn't found a newline character. In this case, it will try to read from the file into the static buffer *temp*. 

If there is no more information to read in the file or there is not a new line, it will break from the loop and it will check if there was information in the dynamically allocated string *line*. If that's the case, it means we have reached the end of the file, and we return the line after appending the character '\0'. If the *line* contained no information, we set all static variables to 0, free the line and return NULL. 

To build the new line, **build line** calls to the function **fill_line**, that appends character by character calling to the function **append_char**, which also sums 1 to the line index. 
**fill_line** function also checks whether the character to append is a '\n' and, in that case, it will append '\0' in the next position. 

**append_char** is also responsible to check whether the dynamically allocated string in which we are appending each character has enough capacity. At the beginning, it will allocate memory for a certain number of bytes and, if there is not enough space, it will duplicate the allocated space until there is space. 

