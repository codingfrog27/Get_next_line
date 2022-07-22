/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/22 19:07:10 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/07/22 19:07:24 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

# include <stdio.h>
# include <strings.h>

char	*get_next_line(int fd);
char	*buff_to_line(char *buff, char *line);
size_t	nlen(char *str, bool look_for_newline);
void	buff_update(char *buff);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif