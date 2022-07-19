/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:31 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/07/19 17:00:19 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	int		read_ret;

	line = calloc(1, sizeof(char));
	if (fd < 0 || fd > OPEN_MAX || read(fd, 0, 0) == -1)
		return (NULL);
	if (*buff != '\0')
		line = buff_to_line(buff, line);
		read_ret = 1;
	while(!nlen(line) && read_ret > 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		buff[read_ret] = '\0';
		line = buff_to_line(buff, line);
	}
	buff_update(buff);
	if (read_ret == 0 && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*buff_to_line(char *buff, char *line)
{
	size_t	line_len = strlen(line);
	size_t	buff_end = nlen(buff);
	if (!buff_end)
		buff_end = strlen(buff) + 1;
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
	npos = nlen(buff);
	bufflen = strlen(buff);
	if (buff[npos] == '\0')
	{
		bzero(buff, BUFFER_SIZE);
		return ;
	}
	while(i <= bufflen - npos)
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

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *line = get_next_line(fd);
	for (int i = 0; i < 20; i++)
	{
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	}
	close(fd);
	return 0;
}
