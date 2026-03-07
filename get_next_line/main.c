#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);

    char *new_line;
    
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