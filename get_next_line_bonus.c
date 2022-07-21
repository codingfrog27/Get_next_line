/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:31 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/07/21 18:48:03 by mde-cloe      ########   odam.nl         */
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
	while(!nlen(line, true) && read_ret > 0)
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

char	*buff_to_line(char *buff, char *line)
{
	size_t	line_len;
	size_t	buff_end;

	line_len = nlen(line, false);
	buff_end = nlen(buff, true);
	if (!buff_end)
		buff_end = nlen(buff, false) + 1;
	char	*line2 = calloc(buff_end + line_len + 1, sizeof(char));
	if (!line2)
		return (NULL);
	strncpy(line2, line, line_len);
	free(line);
	strncat(line2, buff, buff_end);
	return (line2);
}

void buff_update(char *buff)
{
	size_t	i;
	size_t	npos;
	size_t	bufflen;

	i = 0;
	npos = nlen(buff, true);
	bufflen = nlen(buff, false);
	if (buff[npos] == '\0')
	{
		bzero(buff, BUFFER_SIZE);
		return ;
	}
	while (i <= bufflen - npos)
	{
		buff[i] = buff[npos + i];
		i++;
	}
	buff[i] = '\0';
}

//returns the index AFTER \n when used for newline
size_t	nlen(char *str, bool look_for_newline)
{
	size_t	len;

	len = 0;
	if (look_for_newline)
	{
	while (str[len])
	{
		if (str[len] == '\n')
			return (len + 1);
		len++;
	}
	return (0);
	}
	while (str[len])
		len++;
	return (len);
}

