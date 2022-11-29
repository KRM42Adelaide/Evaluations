/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:09:57 by jlane             #+#    #+#             */
/*   Updated: 2022/11/15 14:40:07 by jlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*joins 2 strings while freeing and reallocating.*/

static char	*freejoin(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free(tmp);
	tmp = NULL;
	return (s1);
}

/* locates nl or NULL terminating character in string.
 *when found, NULL terminates and returns the rest.*/

static char	*find_end(char *line)
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	while (line[i] && line[i] != 10)
		i++;
	if (!line[i])
		return (s);
	if (line[i + 1])
		s = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	line[i + 1] = 0;
	return (s);
}

/*Reads fd up to amount of bytes determined by BUFFER_SIZE
 * stores them in bufer. Checks for nl or nulL terminator
 * are found in buffer, if not appends buffer to the string 
 * and reads again.*/

static char	*find_line(int fd, char *line, char *buffer)
{
	int		i;
	int		read_value;

	read_value = read(fd, buffer, BUFFER_SIZE);
	while (read_value != -1)
	{
		if (!read_value)
			return (line);
		buffer[read_value] = 0;
		if (!line)
			line = ft_strdup("");
		line = freejoin(line, buffer);
		i = 0;
		while (line[i] && line[i] != 10)
			i++;
		if (line[i] == 10)
			return (line);
		read_value = read(fd, buffer, BUFFER_SIZE);
	}
	return (NULL);
}

/*Returns a line from fd. If the fd is invalid, returns nothing.
 * BUFFER_SIZE is used to determine how much of the file will be
 * read, as BUFFER_SIZE is randomly determined, any leftover 
 * characters is stored in a static char*/

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	line = find_line(fd, remainder, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	remainder = find_end(line);
	return (line);
}
