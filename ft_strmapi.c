/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emduncan <emduncan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:16:24 by emduncan          #+#    #+#             */
/*   Updated: 2024/05/01 15:16:09 by emduncan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		ctr;

	if (!s || !f)
		return (NULL);
	res = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!res)
		return (NULL);
	ctr = 0;
	while (s[ctr])
	{
		res[ctr] = f(ctr, s[ctr]);
		ctr++;
	}
	res[ctr] = '\0';
	return (res);
}

/*

~ N O T E S ~

A b o u t   F u n c t i o n :

Applies the function 'f' to each character of the string 's',
passing its index as the first argument, to create a new 
string resulting from successive applications of 'f'.


F u n c t i o n   P r o c e s s :

- Handle Empty String or NULL Function Pointer
    - The function checks if the input string or function pointer is invalid.
    - If either is invalid, it returns NULL, indicating an error/invalid input.

- Allocate Memory for Resulting String
    - The function calls ft_strlen to get the length of 's'.
    - It allocates memory for the resulting string res using malloc.
		The size allocated is ft_strlen(s) + 1 to accommodate null terminator.
    - If memory allocation fails, the function returns NULL.

- Loop Through String and Apply Function
	- The function uses a while loop to iterate through the characters of 's'.
    - The loop continues as long as the character at current index is not null.
    - Inside the loop:
        - The function calls the provided function f with two arguments:
        	- ctr: The current index (unsigned integer) in the string.
            - s[ctr]: The character at the current index in the original string.
			- 
        - The result returned by 'f' is stored in (res[ctr]).
        - The counter (ctr) is incremented to move to next character

- Add Null Terminator and Return Result
	- After the loop completes, the function assigns a null terminator to the
		end of the resulting string (res[ctr]).
    - The function returns the result which points to the
	allocated memory containing the modified string.
	
*/