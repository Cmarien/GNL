/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:31:22 by cmarien           #+#    #+#             */
/*   Updated: 2020/12/10 16:42:01 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct	s_list
{
	char	*str;
	int		r;
	int		end;
}				t_list;

#include <stdlib.h>
#include <unistd.h>

int	get_next_line(int fd, char **line);

#endif
