/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:28:57 by kbrown            #+#    #+#             */
/*   Updated: 2022/10/31 16:10:02 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include "ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_data
{
	size_t	i;
	char	c;
}			t_data;

t_data	g_msg;
#endif
