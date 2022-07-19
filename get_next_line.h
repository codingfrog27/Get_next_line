/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:17 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/07/19 16:04:33 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#include <stdio.h>
#include <strings.h>
char	*get_next_line(int fd);
char	*buff_to_line(char *buff, char *line);
size_t	nlen(char *str);
void	buff_update(char *buff);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000000
# endif
#endif