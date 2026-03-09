/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:34:30 by adri              #+#    #+#             */
/*   Updated: 2026/03/09 19:30:30 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fill_line(char **new_line, char letter, int *line_index, int *line_capacity)
{
	*new_line = append_char(*new_line, letter, line_index, line_capacity);
	if (letter == '\n')
	{
		*new_line = append_char(*new_line, '\0', line_index, line_capacity);
		return (1);
	}
	return (0);
}

int	read_bytes(int fd, int *index, int *bytes, char *temp)
{
	if (*index == 0)
		*bytes = read(fd, temp, BUFFER_SIZE);
	if (*bytes <= 0)
		return (-1);
	return (0);
}

void	free_and_set(char **new_line, int *index, int *bytes, char *temp)
{
	if (new_line)
		free (new_line);
	ft_memset(temp, 0, BUFFER_SIZE);
	*index = 0;
	*bytes = 0;
}

char	*build_line(int fd, char **new_line)
{
	static int	bytes;
	static int	temp_idx;
	static char	temp[BUFFER_SIZE];
	int			line_idx;
	int			line_cap;

	line_cap = 0;
	line_idx = 0;
	while (1)
	{
		if (read_bytes(fd, &temp_idx, &bytes, temp) == -1)
			break ;
		while (temp_idx < bytes)
		{
			if (fill_line(new_line, temp[temp_idx++], &line_idx, &line_cap))
				return (*new_line);
		}
		temp_idx = 0;
	}
	if (*new_line != NULL)
	{
		*new_line = append_char(*new_line, '\0', &line_idx, &line_cap);
		return (*new_line);
	}
	free_and_set(new_line, &temp_idx, &bytes, temp);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*new_line;

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
