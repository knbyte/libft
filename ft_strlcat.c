/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emduncan <emduncan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:07:29 by emduncan          #+#    #+#             */
/*   Updated: 2024/04/25 18:31:43 by emduncan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t destsize)

{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;

	if ((!dest || !src) && !destsize)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	if (dest_len >= destsize)
		return (src_len + destsize);
	ft_strlcpy(dest + dest_len, src, destsize - dest_len);
	return (total_len);
}

/*

~ N O T E S ~

A b o u t   F u n c t i o n :

strlcat stands for "String Length Concatenate"
The strlcat function appends the string s2 to the string s1, always
NUL terminating the resulting string.

F u n c t i o n   P r o c e s s :

We declare three variables, dest_len, which is the length of the string
dest, src_len, which is the length of the string src, and total_len, which
is the length of the concatenated string.

We check if the destination buffer is large enough to accommodate the
concatenation.

We define dest_len as ft_strlen(dest) and src_len as ft_strlen(src).
We define total_len as dest_len + src_len.

We check if the destination buffer is too small to accommodate the
concatenation. If it is, we return the length that would have been
copied if the buffer were large enough.

We use the ft_strlcpy function to copy up to destsize - 1 characters
from src to dest, ensuring null termination. We return the total length
of the concatenated string.

M a i n   F o r   T e s t i n g : */
/*
int	main(void)
{
	char	dest[50];
	char	src[] = "This is a test string";
	int		len;
	
	ft_bzero(dest, 50);
	ft_strlcpy(dest, "Hello ", 50);
	len = ft_strlcat(dest, src, 50);
	printf("%s\n", dest);
	printf("%d\n", len);

	return (0);
}
*/