/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:22:39 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/27 23:18:12 by obelaizi         ###   ########.fr       */
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

	line = get_next_line(fd);
	if (!line)
		return (0);
	len = ft_strlen(line);
	ft_lstadd_back(head, ft_lstnew(line));
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_lstclear(head), 0);
		ft_lstadd_back(head, ft_lstnew(line));
		if (line && ft_strlen(line) == len - 1 && line[len - 1] != '\n')
			break ;
		else if (line && len != ft_strlen(line))
			return (ft_lstclear(head), 0);
	}
	return (1);
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
		check += check_line_valid(head->data, "01PCE");
		head = head->next;
	}
	if (p != 1 || e != 1 || c < 1 || check)
		return (0);
	return (1);
}

int	first_last_1(char *str)
{
	int	len;

	if (*str != '1')
		return (0);
	len = ft_strlen(str) - 2;
	if (str[len] != '1')
		return (0);
	return (1);
}

int	check_map_closed(t_line *head)
{
	if (check_line_valid(head->data, "1") || check_line_valid(ft_lstlast(head)->data, "1"))
		return (0);
	head = head->next;
	while (head->next)
	{
		if (!first_last_1(head->data))
			return (0);
		head = head->next;
	}
	return (1);
}

char *fill_untl_nl(char *str)
{
	int		len;
	int		i;
	char	*line;

	i = 0;
	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		len--;
	line = malloc(len + 1);
	if (!line)
		return (0);
	line[len] = 0;
	while (*str && *str != '\n')
	{
		line[i++] = *str;
		str++;
	}
	return (line);
}

void	free_str(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

char	**fill_dbl_string(t_line *head)
{
	int		total_lines;
	int		i;
	char	**map;
	int		len_line;

	i = 0;
	len_line = ft_strlen(head->data) - 1;
	total_lines = ft_lstsize(head);
	map = malloc((total_lines + 1) * (sizeof(char *)));
	map[total_lines] = NULL;
	while (head)
	{
		map[i] = fill_untl_nl(head->data);
		if (!map[i])
			return (free_str(map, i), NULL);
		i++;
		head = head->next;
	}
	return (map);
}

int	get_x(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (j);
			j++;
		}
		i++;
	}
	return (2147483647);
}

int	get_y(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (2147483647);
}

int	search_top(char **map, int x, int y)
{
	printf("x->(%d) y->(%d)\n", x, y);
	if (map[y][x] == 'E' || map[y][x + 1] == 'E' || map[y][x - 1] == 'E')
		return (printf("fafawf"), 1);
	if (map[y][x + 1] == '0')
		search_top(map, x + 1, y);
	if (map[y][x - 1] == '0')
		search_top(map, x - 1, y);
	if (map[y - 1][x] == '0')
		search_top(map, x, y - 1);
}

int	search_bottom(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (printf("there is exit"), 1);
	if (map[y][x + 1] == '0')
		search_top(map, x + 1, y);
	if (map[y][x - 1] == '0')
		search_top(map, x - 1, y);
	if (map[y + 1][x] == '0')
		search_top(map, x, y + 1);
}

int	check_exit(t_line *head)
{
	char	**map;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;

	map = fill_dbl_string(head);
	if (!map)
		return (0);
	p_x = get_x(map, 'P');
	p_y = get_y(map, 'P');
	e_x = get_x(map, 'E');
	e_y = get_y(map, 'E');
	if (e_y > p_y)
		search_bottom(map, p_x, p_y);
	else
		search_top(map, p_x, p_y);
}

int	map_error(char *path)
{
	int		fd;
	int		len;
	t_line	*head;

	head = NULL;
	fd = open(path, O_RDWR);
	if (fd == -1 || check_map_name(path) || !check_rectangle(fd, &head)
		|| !check_map_inside(head) || !check_map_closed(head))
		return (1);
	if (!check_exit(head))
		return (1);
	return (0);
}
