/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:31:22 by cmarien           #+#    #+#             */
/*   Updated: 2020/12/15 17:29:18 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	char	*str;
	int		r;
	int		end;
}				t_list;

int				get_next_line(int fd, char **line);
int				ch_n(char *str);
char			*str_edit(char *str, int end);
#endif
