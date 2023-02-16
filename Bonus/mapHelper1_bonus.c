/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapHelper1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:15:09 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/14 18:49:12 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map_name(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (1);
	len = ft_strlen(path) - 4;
	if (!ft_strncmp(path + len, ".ber", 4))
		return (0);
	ft_putstr_fd("Error\nDude enter a valid name ;)", 2);
	return (exit (1), 1);
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

	ft_lstadd_back(head, ft_lstnew(get_next_line(fd)));
	if (!((*head)->data))
	{
		ft_putstr_fd("Error\nThere is no map dude ;)", 2);
		return (ft_lstclear(head), exit(1), 0);
	}
	line = (*head)->data;
	len = ft_strlen(line);
	while (line)
	{
		line = get_next_line(fd);
		ft_lstadd_back(head, ft_lstnew(line));
		if (line && ft_strlen(line) == len - 1 && line[len - 2] != '\n')
			return (1);
		else if (line && len != ft_strlen(line))
		{
			ft_putstr_fd("Error\nThis Map is not rectangel Be careful :)", 2);
			return (ft_lstclear(head), exit(1), 0);
		}
	}
	ft_putstr_fd("Error\nThis Map is not rectangel Be careful :)", 2);
	return (ft_lstclear(head), exit(1), 0);
}

int	check_line_valid(char *src, const char *check)
{
	while (*src)
	{
		if (*src != '\n' && !count_char(check, *src))
			return (1);
		src++;
	}
	return (0);
}

int	check_map_inside(t_line *head)
{
	int		p;
	int		c;
	int		e;
	int		check;

	c = 0;
	p = 0;
	check = 0;
	e = 0;
	while (head)
	{
		p += count_char(head->data, 'P');
		c += count_char(head->data, 'C');
		e += count_char(head->data, 'E');
		check += check_line_valid(head->data, "01PCEN");
		head = head->next;
	}
	if (p != 1 || e != 1 || c < 1 || check)
	{
		ft_putstr_fd("Error\nDon't Enter Something sus :)", 2);
		return (exit(1), 0);
	}
	return (1);
}
