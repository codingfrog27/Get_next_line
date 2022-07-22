/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:31 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/07/22 18:45:38 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Todo: replace: calloc, strncpy and strncat with homemade functions

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	int			read_ret;

	line = calloc(1, sizeof(char));
	if (fd < 0 || fd > OPEN_MAX || read(fd, 0, 0) == -1)
		return (NULL);
	if (*buff != '\0')
		line = buff_to_line(buff, line);
		read_ret = 1;
	while (!nlen(line, true) && read_ret > 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		buff[read_ret] = '\0';
		line = buff_to_line(buff, line);
	}
	buff_update(buff);
	if (read_ret == 0 && *line == '\0')
		return (free(line), NULL);
	return (line);
}
