/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:38:04 by obelaizi          #+#    #+#             */
/*   Updated: 2023/01/26 23:44:39 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

int		ft_len(char *s);
int		check_char(char *s, char c);
char	*ft_strdup(const char *src);
char	*ignore(char *s);
char	*fill(char *src);
char	*get_next_line(int fd);
int		handle_error(char *rest, int fd);

#endif