/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:34:30 by adri              #+#    #+#             */
/*   Updated: 2026/03/10 19:41:24 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
fill_line appends a given character. It also checks if the character is a '\n'.
In that case, it appends a '\0' in the next position (because append_char sums 1
to the position of the pointer everytime is called). 

Return value:
- 1 if the character '\n' was found. 
- 0 if the character '\n' was not found. 
*/
int	fill_line(char **line, char ch, int *line_index, int *line_capacity)
{
	*line = append_char(*line, ch, line_index, line_capacity);
	if (ch == '\n')
	{
		*line = append_char(*line, '\0', line_index, line_capacity);
		return (1);
	}
	return (0);
}

/*
read_bytes checks if there is information in the static buffer 'temp'.
If index is 0 it means the buffer is empty and didn't find an '\n' in the 
last function call, so it reads again. 
If index is different than 0, it was reading from the buffer so it contains
information. 

Return value:
- 0 if there are is more information or bytes to read (either new information if
	index is 0 or previous information if not).
- '-1' if there are no more bytes to read. 
*/
int	read_bytes(int fd, int *index, int *bytes, char *temp)
{
	if (*index == 0)
		*bytes = read(fd, temp, BUFFER_SIZE);
	if (*bytes <= 0)
		return (-1);
	return (0);
}

/*
build_line continuosly checks if there are more bytes to read or there 
is a new line.

Return value:
- A dynamically allocated string finished in '\n' if the character is found.
- A dynamically allocated string finished in '\0' if '\n' is not found.
- NULL if there is nothing left to read and there is nothing in new line.
*/
char	*build_line(int fd, int *bytes, int *temp_idx, char *temp)
{
	int			line_idx;
	int			line_cap;
	char		*line;

	line_cap = 0;
	line_idx = 0;
	line = NULL;
	while (1)
	{
		if (read_bytes(fd, temp_idx, bytes, temp) == -1)
			break ;
		while (*temp_idx < *bytes)
		{
			if (fill_line(&line, temp[(*temp_idx)++], &line_idx, &line_cap))
				return (line);
		}
		*temp_idx = 0;
	}
	if (line != NULL)
	{
		line = append_char(line, '\0', &line_idx, &line_cap);
		return (line);
	}
	free_and_set(&line, temp_idx, bytes, temp);
	return (NULL);
}

/*
get_next_line reads from file descriptor (fd) and returns the next line. 
The information is kept in a static buffer (temp) between function calls.
Also, the static index saves the last position we copied from to the new line, 
and with the static bytes, we know how much we read in the last function call. 

Return value:
- A dynamically allocated string containing the next line from the file,
	that must be freed by the caller. 
- NULL if there is nothing left to read or if an error occurs.
*/
char	*get_next_line(int fd)
{
	static int	bytes;
	static int	temp_idx;
	static char	temp[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_memset(temp, 0, BUFFER_SIZE);
		temp_idx = 0;
		bytes = 0;
		return (NULL);
	}
	else
	{
		return (build_line(fd, &bytes, &temp_idx, temp));
	}
}
