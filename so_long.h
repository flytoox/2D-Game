/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:23:10 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/26 23:46:13 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "Libft/libft.h"
# include "gnl/get_next_line.h"


typedef struct line
{
	char		*data;
	struct line	next;
}t_line;


int	map_error(char *path);

#endif