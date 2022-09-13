/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:34:55 by khaynes           #+#    #+#             */
/*   Updated: 2022/07/25 12:59:16 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *buf, char *mem)
{
	int		readline;
	char	*temp_mem;

	readline = 1;
	while (readline != '\0')
	{
		readline = read(fd, buf, BUFFER_SIZE);
		if (readline == -1)
			return (0);
		else if (readline == 0)
			break ;
		buf[readline] = '\0';
		if (!mem)
			mem = ft_strdup("");
		temp_mem = mem;
		mem = ft_strjoin(temp_mem, buf);
		free(temp_mem);
		temp_mem = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (mem);
}

/*
 1. The code is a function that takes in an integer fd and a pointer to the string 
 "mem" as parameters.
 2. The function returns the value of mem if it is not NULL, otherwise it returns 0.
 3. The first thing this code does is declare variables for readline and temp_mem.
 4. Then it declares a variable called BUFFER_SIZE which will be used later on to 
 store how many bytes are currently being read from the file descriptor fd.
 5. Next, the program starts by declaring that readline equals 1 while reading from 
 fd until there is no more data left to be read (readline == '\0').
 6. This means that every time we call this function with a new line of input, we'll 
 increment readline by one so when we eventually reach '\0', then our loop will end 
 because there's nothing else left to do.
 7. Next, inside the loop, if there was an error reading from fd (i.e., -1), then 
 break out of the loop and return 0; otherwise continue on into another iteration 
 of checking whether or not buf has any more data in it before returning what's 
 stored at buf[readline].
 8. If none exists yet, then create a new string using ft_str
 9. The code is used to read a line from the file descriptor fd.
 10. The function returns the string that was read in buf, or NULL if an error 
 occurred.
 11. The code above will return NULL if an error occurs.
*/

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
	}
	line[count + 1] = '\0';
	return (mem);
}

/*
 1. The code is trying to extract a line from the file.
 2. The code starts by setting up a variable called count that will be used to 
 keep track of how many characters are in the string.
 3. It then loops through each character in the string, and increments count by 
 one for every loop iteration.
 4. If it encounters an end-of-line character (a newline or 0), it returns 0; 
 otherwise, it continues on with the next iteration of counting characters until 
 it reaches the end of line.
 5. After extracting all but one character from line, mem is set to point at that 
 last remaining character and free(mem) is called so that memory can be reused for 
 other purposes later on.
 6. Finally, after extracting all but one character from line, mem is set to NULL 
 so that any subsequent calls won't try to use this value again.
 7. The program starts by creating a variable called count which will hold how 
 many characters are in each string passed into f_substr().
 8. It then sets up another variable called mem which points at where we want our 
 extracted text stored once we've finished extracting everything except for one 
 charater left over at the end of our original input string After getting rid of 
 whitespace using ft_substr(), we store
 9. The code will extract the first line of a file and return it as a string.
 10. The code will extract the last line of a file and return it as a string.
*/

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*mem;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = ft_read_line(fd, buf, mem);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	mem = extract_line(line);
	return (line);
}

/*
 1. The code is reading a file line by line and storing the lines in an array.
 2. The first line is stored at index 0, the second at index 1, etc.
 3. The code starts by checking if fd is less than 0 or BUFFER_SIZE is less than 0.
 4. If either of these conditions are true then it returns (0).
 5. Otherwise it allocates memory for a buffer that can hold up to BUFFER_SIZE + 1 
 characters and stores this in buf before calling ft_read_line() to read one line 
 from the file into this buffer.
 6. It then frees the allocated memory with free().
 7. Finally, if there was no data returned from ft_read(fd) then it returns NULL.
 8. The code is used to read a line from the file descriptor fd.
 9. If the file descriptor fd is greater than 0, then the code will allocate memory 
 for a buffer of size BUFFER_SIZE and store it in buf.
 10. If buf is not allocated, then the code will return NULL.
 11. The ft_read_line function is called with the file descriptor fd and buf as 
 arguments.
 12. The ft_read_line function reads one line from the file descriptor fd into buf 
 and returns that line's address in mem which can be used to extract that line's 
 content later on.
*/