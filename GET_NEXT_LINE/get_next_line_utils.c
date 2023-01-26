/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:41:18 by obelaizi          #+#    #+#             */
/*   Updated: 2022/11/14 21:37:50 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_char(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	size_t		i;
	int			j;
	char		*cp;

	j = 0;
	i = ft_strlen((char *)src);
	cp = malloc((i + 1) * sizeof(char));
	if (!cp)
		return (0);
	while (i)
	{
		cp[j] = src[j];
		j++;
		i--;
	}
	cp[j] = 0;
	return (cp);
}

int	handle_error(char *rest, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (1);
	if (read(fd, NULL, 0) < 0)
	{
		if (rest)
			free(rest);
		rest = NULL;
		return (1);
	}
	return (0);
}
