/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:08:45 by khaynes           #+#    #+#             */
/*   Updated: 2022/07/25 12:41:37 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cast_sub;

	cast_sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (cast_sub == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			cast_sub[j] = s[i];
			j++;
		}
		i++;
	}
	cast_sub[j] = 0;
	return (cast_sub);
}

/*
1. The code is trying to find the substring of a string that starts at position 
start and ends at len.
2. The code first allocates memory for the length of the string, then it loops 
 through all characters in the string until it finds one that is not equal to 0.
3. It then stores this character into cast_sub[j] and increments j by 1.
4. Finally, cast_sub[j] is set back to 0 so that when you return from this 
 function, you will be returning a pointer to where you started instead of a 
 pointer past your end point.
5. The code allocates a char array of size len + 1 and copies the string s into it.
6. The code then iterates through the string, copying each character in turn 
 to the newly allocated array.
7. At the end of this loop, cast_sub will be set to point to the last element of 
 s and 0 will be written at that position.
*/

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

/*
1. The code is trying to find the first occurrence of a character in a string.
2. The code starts by checking if the current character is equal to c, which is the 
 last character in s. If it is, then it returns that location as its return value.
3. Otherwise, it increments s and checks again until it finds an occurrence of 
 c or reaches the end of s.
4. The code will return the first occurrence of a character c in string s. 
*/

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*cast_dup;

	i = 0;
	s_len = ft_strlen(s);
	cast_dup = (char *)malloc(sizeof(*cast_dup) * (i + 1));
	while (i < s_len)
	{
		cast_dup[i] = s[i];
		i++;
	}
	cast_dup[i] = '\0';
	return (cast_dup);
}

/*
1. The code is a function that takes in a string and returns a pointer to the 
first character of the string.
2. The code starts by initializing an integer variable called i with 0.
3. Next, it calculates how many characters are in the string s using ft_strlen(s).
4. It then allocates memory for cast_dup, which is going to be used as a 
 temporary buffer for storing each character from s until there are no more 
 characters left in s. The loop iterates through all of the characters in s 
 and stores them into cast_dup one at a time starting with index 0 (the first 
 character) and incrementing by 1 after each iteration.
5. After all of the iterations have been completed, cast_dup will contain all 
zeros except for '\0'.
6. The code is a function that allocates memory for the string and copies it 
to the allocated memory.
7. The code then iterates through the string, copying each character to the 
allocated memory until it reaches the end of the string.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*j_str;

	i = 0;
	j = 0;
	j_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (j_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		j_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		j_str[i + j] = s2[j];
		j++;
	}
	j_str[i + j] = '\0';
	return (j_str);
}


