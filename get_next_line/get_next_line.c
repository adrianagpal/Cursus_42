/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:34:30 by adri              #+#    #+#             */
/*   Updated: 2026/03/07 02:05:28 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char    *build_line(int fd)
{
    static int bytes;
    static int temp_index;
    static char    temp[BUFFER_SIZE];
    char    *new_line;    
    int newline_index;
    int newline_capacity;
    char letter;

    newline_capacity = 0;
    newline_index = 0;
    new_line = NULL;
    while (1)
    {
        if (read_bytes(fd, &temp_index, &bytes,  temp) == -1)
            break ;
        while (temp_index < bytes)
        {
            letter = temp[temp_index];
            temp_index++;
            if (fill_line(&new_line, letter, &newline_index, &newline_capacity) == 1)
                return (new_line);
        }
        temp_index = 0;
    }
    if (new_line != NULL)
    {
        new_line = append_char(new_line, '\0', &newline_index, &newline_capacity);                    
        return (new_line);
    }
    free (new_line);
    return (NULL);
}

char    *get_next_line(int fd)
{
    if (fd < 0)
    {
        return (NULL);
    }
    else
    {
        return (build_line(fd));
    }
}
