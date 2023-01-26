/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:38:04 by obelaizi          #+#    #+#             */
/*   Updated: 2022/11/14 21:32:05 by obelaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(char *s);
int		check_char(char *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ignore(char *s);
char	*fill(char *src);
char	*get_next_line(int fd);
int		handle_error(char *rest, int fd);

#endif