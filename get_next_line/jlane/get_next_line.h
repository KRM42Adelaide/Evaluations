/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:47:15 by jlane             #+#    #+#             */
/*   Updated: 2022/11/15 13:33:52 by jlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char*s1, const char *s2);
char		*ft_strdup(const char *s1);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);

#endif
