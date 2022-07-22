/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:17 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/07/22 22:14:19 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

char	*get_next_line(int fd);
char	*buff_to_line(char *buff, char *line);
size_t	nl_strlen(char *str, bool look_for_newline);
void	buff_update(char *buff);
void	strcopycat(char *dst, char *cpysrc, char *catsrc, \
size_t catlen);
char	*stralloc(size_t space);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif