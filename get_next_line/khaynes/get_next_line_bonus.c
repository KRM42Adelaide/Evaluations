


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:34:55 by khaynes           #+#    #+#             */
/*   Updated: 2022/07/25 12:58:52 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *line)
{
	size_t	count;
	char	*mem;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	mem = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*mem == '\0')
	{
		free(mem);
		mem = NULL;

	line[count + 1] = '\0';
	return (mem);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*mem[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = ft_read_line(fd, buf, mem[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	mem[fd] = extract_line(line);
	return (line);
}
