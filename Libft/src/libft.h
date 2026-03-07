/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:50:53 by adri              #+#    #+#             */
/*   Updated: 2025/08/20 21:14:35 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <string.h>

int     ft_isalpha(unsigned char c);
int     ft_isdigit(unsigned char c);
int     ft_isalnum(unsigned char c);
int     ft_isascii(unsigned char c);
int     ft_isprint(unsigned char c);
size_t  ft_strlen(const char* str);
void    *ft_memset(void *ptr, int x, size_t n);
void    *ft_bzero(void *ptr, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
size_t  ft_strlcpy(char *dest, const char *src, size_t buffer);
size_t  ft_strlcat(char *dest, const char *src, size_t buffer);
int  ft_toupper(int c);   
int  ft_tolower(int c);      
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);     
int    ft_strncmp(const char *s1, const char *s2, size_t n);  
void    *ft_memchr(const void *s, int c, size_t n);
int    ft_memcmp(const void *s1, const void *s2, size_t n);

#endif