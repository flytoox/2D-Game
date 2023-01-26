/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:22:39 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/25 13:49:07 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(char *path)
{
	int	len;

	if (len < 4)
		return (1);
	len = ft_strlen(path) - 4;
	if (!ft_strncmp(path + len, ".ber", 4))
		return (0);
	return (1);
}

int	map_error(char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd == -1 || check_map_name(path))
		return (1);
	return (0);
}
