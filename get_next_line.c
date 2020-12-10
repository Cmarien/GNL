/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:43:07 by cmarien           #+#    #+#             */
/*   Updated: 2020/12/10 19:07:52 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ch_n(char *str)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == '\n')
			j++;
	return (j);
}

char	*ft_join(char *s1, char *s2)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			i++;
	while (s2[j])
		j++;
	if (!(str = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

t_list	read_line(int fd, t_list lst)
{
	int ret;
	char buff[BUFFER_SIZE + 1];

	lst.end = 0;
	ret = 0;
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		lst.str = ft_join(lst.str, buff);
		if ((lst.r = ch_n(lst.str)) > 0 || ret < BUFFER_SIZE)
			break ;
	}
	if (ret == 0)
		lst.end = -1;
	return (lst);
}

char	*s_dup(char *str)
{
	int i;
	char *line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*str_edit(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i++])
		str[j++] = str[i];
	str[j] = '\0';
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static t_list	lst;

	if (fd < 0 || line == NULL || !fd)
		return (-1);
	if (!(lst.str))
	{
		if (!(lst.str = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		lst.r = 0;
	}
	if (lst.r == 0)
		lst = read_line(fd, lst);
	*line = s_dup(lst.str);
	lst.str = str_edit(lst.str);
	if (lst.r > 0)
		lst.r--;
	if (lst.end == -1)
		return (0);
	return (1);
}
