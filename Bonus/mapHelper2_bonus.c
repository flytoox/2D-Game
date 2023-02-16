/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapHelper2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:15:59 by obelaizi          #+#    #+#             */
/*   Updated: 2023/02/14 18:29:22 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (check_line_valid(head->data, "1")
		|| check_line_valid(ft_lstlast(head)->data, "1"))
	{
		ft_putstr_fd("Error\nThis Map is not Closed :)", 2);
		return (exit(1), 0);
	}
	head = head->next;
	while (head->next)
	{
		if (!first_last_1(head->data))
		{
			ft_putstr_fd("Error\nThis Map is not Closed :)", 2);
			return (exit(1), 0);
		}
		head = head->next;
	}
	return (1);
}

char	*fill_untl_nl(char *str)
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

	i = 0;
	total_lines = ft_lstsize(head);
	map = malloc((total_lines + 1) * (sizeof(char *)));
	if (!map)
		return (exit(1), NULL);
	map[total_lines] = NULL;
	while (head)
	{
		map[i] = fill_untl_nl(head->data);
		if (!map[i])
			return (free_str(map, i), exit(1), NULL);
		i++;
		head = head->next;
	}
	return (map);
}
