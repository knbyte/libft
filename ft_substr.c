/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emduncan <emduncan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:14:34 by emduncan          #+#    #+#             */
/*   Updated: 2024/04/29 19:09:34 by emduncan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned long	ctr;

	if (!s)
		return (NULL);
	if (start >= (unsigned long)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ctr = 0;
	while (ctr < len && s[start + ctr])
	{
		res[ctr] = s[start + ctr];
		ctr++;
	}
	res[ctr] = '\0';
	return (res);
}

/*

~ N O T E S ~

A b o u t   F u n c t i o n :

Allocates (with malloc(3)) and returns a substring from the string 's'.
The substring begins at index 'start' and is of maximum size 'len'.


F u n c t i o n   P r o c e s s :

- Variable Declaration
	- result, a character pointer to store the resulting substring
	- ctr, unsigned long variable (can hold large non-negative integers)
		used as a counter for the loop.

- Handle Empty String
	- If the string 's' is null, we return NULL.

- Handle Start Index Out of Bounds
	- If 'start' index is greater than or equal to the length of the string,
		call str_dup to create a copy of an empty string and return that pointer.

- Handle Length Beyond String Bounds
	- If 'len' is greater than the length of the string starting from 'start',
		adjust 'len' to be the maximum possible length within the string
			starting from start.

- Allocate Memory for Substring
	- Allocates memory for the substring using malloc.
	- The size is calculated as len + 1 to accommodate all characters and
		the null terminator.
	- If allocation fails, we return NULL.

- Copy Characters and Add Null Terminator
	- Iterates as long as ctr is less than len (desired length) and the
		character at 's[start + ctr]' is not null (within the string bounds).
	- Inside Loop
		- Copies the character from the original string (s) at the specified
		index (start + ctr) to the corresponding position in the result (res).
		- Increments ctr
	- After the loop, we set the null terminator to end of allocated memory.

- Return Substring
	- Returns the pointer res which points to the allocated memory containing
		the created substring.
*/