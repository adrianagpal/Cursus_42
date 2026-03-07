/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:34:36 by adri              #+#    #+#             */
/*   Updated: 2026/03/07 01:48:32 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
char    *ft_realloc(char *ptr, size_t size, int n_char);
char    *append_char(char *ptr, char letter, int *ptr_index, int *capacity);
int fill_line(char **new_line, char letter, int *newline_index, int *newline_capacity);
int read_bytes(int fd, int *index, int *bytes, char *temp);
char    *build_line(int fd);
char    *get_next_line(int fd);

#endif