/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emduncan <emduncan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:14:10 by emduncan          #+#    #+#             */
/*   Updated: 2024/04/29 18:59:12 by emduncan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		ctr;

	ctr = 0;
	while (src[ctr] != '\0')
		ctr++;
	dest = (char *)malloc(sizeof(char) * (ctr + 1));
	if (dest == NULL)
		return (NULL);
	ctr = 0;
	while (src[ctr] != '\0')
	{
		dest[ctr] = src[ctr];
		ctr++;
	}
	dest[ctr] = '\0';
	return (dest);
}

/*

~ N O T E S ~

A b o u t   F u n c t i o n :

strdup stands for "String Duplicate"
The strdup function allocates sufficient memory for a copy of
the string s1, does the copy, and returns a pointer to it.

F u n c t i o n   P r o c e s s :

We initialize two variables, ctr, which is a counter variable used to 
ount the number of characters in the string, and dest, which is a
pointer to the allocated memory.

We set ctr to 0, to count the number of characters in the string, and count
through the string until we reach the null character.

We then allocate sufficient memory for a copy of the string using the
malloc function.  If the memory allocation fails, we return NULL.

We then reset the counter to 0 to count through the string again and
copy each character into the allocated memory.  Finally, we set the
null character to the end of the string and return the allocated memory.

M a i n   F o r   T e s t i n g : */
/*
#include <stdio.h>
#include <strings.h>

int    main(void)
{
    char    *src;
    char    *dst;
	char	*dst2;

    src = "Source";
    dst = ft_strdup(src);
	dst2 = strdup(src);
    printf("ft_strdup result: %s\n", dst);
	printf("regular strdup result: %s\n", dst2);
    return (0);
}
*/