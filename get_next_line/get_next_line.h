/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:34:36 by adri              #+#    #+#             */
/*   Updated: 2026/03/10 21:06:36 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_realloc(char *ptr, size_t size, int n_char);
char	*append_char(char *ptr, char letter, int *ptr_index, int *capacity);
int		fill_line(char **line, char ch, int *line_index, int *line_capacity);
int		read_bytes(int fd, int *index, int *bytes, char *temp);
char	*build_line(int fd, int *bytes, int *temp_idx, char *temp);
void	*ft_memset(void *s, int c, size_t n);
void	free_and_set(char **new_line, int *index, int *bytes, char *temp);
char	*get_next_line(int fd);

#endif
