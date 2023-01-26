/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:22:39 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/26 23:52:00 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (1);
	len = ft_strlen(path) - 4;
	if (!ft_strncmp(path + len, ".ber", 4))
		return (0);
	return (1);
}

int	count_char(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

int	check_rectangle(int fd, t_line **head)
{
	char	*line;
	size_t	len;

	// (*head)->data = get_next_line(fd);
	line = get_next_line(fd);
	// if (!(*head)->data)
	// 	return (0);
	len = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strlen(line) == len - 1 && line[len - 1] != '\n')
			break ;
		else if (!line)
			return (0);
		if (line && len != ft_strlen(line))
			return (free(line), 0);
	}
	return (get_next_line(-1), 1);
}

int	check_map_inside(int fd)
{
	int		p;
	int		c;
	int		e;
	char	*line;

	c = 0;
	p = 0;
	e = 0;
	line = get_next_line(fd);
	while (line)
	{
		p += count_char(line, 'P');
		c += count_char(line, 'C');
		e += count_char(line, 'E');
		free(line);
		line = get_next_line(fd);
	}
	printf("%d %d %d", p, e, c);
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}

int	map_error(char *path)
{
	int		fd;
	int		len;
	t_line	*head;

	fd = open(path, O_RDWR);
	if (fd == -1 || check_map_name(path) || !check_rectangle(fd, &head) 
		|| !check_map_inside(fd))
		return (1);
	return (0);
}
