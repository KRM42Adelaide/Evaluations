/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:08:45 by khaynes           #+#    #+#             */
/*   Updated: 2022/07/25 12:41:50 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cast_sub;

	cast_sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (cast_sub == NULL)
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
	cast_sub[j] = '\0';
	return (cast_sub);
}

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
