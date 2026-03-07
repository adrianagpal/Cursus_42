# define BUFFER_SIZE 1000000
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (!dest && !src)
	{
		return (NULL);
	}
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		ptr_dest[index] = ptr_src[index];
		index++;
	}
	return (dest);
}

char    *ft_realloc(char *ptr, size_t size, int n_char)
{
    char    *line;

    line = malloc(sizeof(char) * size);
    if (!line)
        return (NULL);
    if (ptr)
    {
        ft_memcpy(line, ptr, n_char);
        free (ptr);
        ptr = NULL;
    }    
    return (line);
}

char    *append_char(char *ptr, char letter, int *ptr_index, int *capacity)
{
    if (*ptr_index == 0)
    {
        *capacity = 32;
        ptr = ft_realloc(ptr, *capacity + 1, *ptr_index);
    }   
    if (*ptr_index > *capacity)
    {
        *capacity *= 2;
        ptr = ft_realloc(ptr, *capacity + 1, *ptr_index);
    }
    ptr[*ptr_index] = letter;
    (*ptr_index)++;

    return (ptr);
}

int fill_line(char **new_line, char letter, int *newline_index, int *newline_capacity)
{
    *new_line = append_char(*new_line, letter, newline_index, newline_capacity);
    if (letter == '\n')
    {        
        *new_line = append_char(*new_line, '\0', newline_index, newline_capacity);
        return (1);
    }
    return (0);
}

int read_bytes(int fd, int *index, int *bytes, char *temp)
{
    if (*index == 0)
        *bytes = read(fd, temp, BUFFER_SIZE);

    if (*bytes <= 0)
        return (-1);

    return (0);
}

char    *build_line(int fd, char **new_line)
{
    static int bytes;
    static int temp_index;
    static char    temp[BUFFER_SIZE];  
    int newline_index;
    int newline_capacity;

    newline_capacity = 0;
    newline_index = 0;
    while (1)
    {
        if (read_bytes(fd, &temp_index, &bytes,  temp) == -1)
            break ;
        while (temp_index < bytes){
            if (fill_line(new_line, temp[temp_index++], &newline_index, &newline_capacity) == 1)
                return (*new_line);
        }
        temp_index = 0;
    }
    if (*new_line != NULL){
        *new_line = append_char(*new_line, '\0', &newline_index, &newline_capacity);                    
        return (*new_line);
    }
    free (*new_line);
    return (NULL);
}

char    *get_next_line(int fd)
{
    char    *new_line; 
    
    new_line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return (NULL);
    }
    else
    {
        return (build_line(fd, &new_line));
    }
}

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

