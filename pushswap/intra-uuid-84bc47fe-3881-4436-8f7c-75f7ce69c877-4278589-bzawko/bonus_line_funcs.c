/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_line_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:08:41 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:08:43 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(char *list, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!list)
	{
		list = malloc(1);
		list[0] = '\0';
	}
	if (!list || !buffer)
		return (NULL);
	ret = malloc(ft_strlen(list) + ft_strlen(buffer) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	j = 0;
	while (list[++i])
		ret[i] = list[i];
	while (buffer[j])
		ret[i++] = buffer[j++];
	ret[ft_strlen(list) + ft_strlen(buffer)] = '\0';
	free(list);
	return (ret);
}

char	*get_list(char *list)
{
	char	*buf;
	int		i;

	buf = malloc(2);
	if (!buf)
	{
		write(2, "Mem Error\n", 10);
		exit (0);
	}
	i = 1;
	while (i && !is_in_string(list, '\n'))
	{
		i = read(0, buf, 1);
		if (i == -1)
		{
			free(buf);
			write(2, "Read Error\n", 11);
			exit(0);
		}
		buf[i] = '\0';
		list = ft_strjoin(list, buf);
	}
	free(buf);
	return (list);
}
