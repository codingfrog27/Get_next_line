/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:31 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/07/06 20:23:21 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	int		read_ret;

	line = NULL;
	if (fd < 0 || fd > OPEN_MAX || read(fd, 0, 0) == -1)
		return (NULL);
	if (*buff != '\0')
		line = buff_to_line(buff, line);
		if (!line)
			return (NULL);
	while(nlen(line) == 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		buff[read_ret] = '\0';
		line = buff_to_line(buff, line);
	}
	//buff_update(buff);
	if (read_ret == 0 && *line == '\0')
		return (NULL);
	//buff_update //if \n is in the middle of the buffer you need to move the remainder to the start of the buffer
	return (line);
}


char	*buff_to_line(char *buff, char *line)
{
	size_t	line_len = strlen(line);
	size_t	buff_end = nlen(buff);
	if (!buff_end)
		buff_end = strlen(buff);

	size_t line2_len = buff_end + line_len;
	char	*line2 = malloc(line2_len);
	if (!line2)
		return (NULL);
	strncpy(line2, line, line_len);
	free(line);
	strncat(line2, buff, line2_len);
	return (line2);
}

void buff_update(char *buff)
{
	char	tmp[BUFFER_SIZE + 1];


}


size_t	nlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
			return (len);
		len++;
	}
	return (0);
}
int main()
{
	int fd = open("text.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	while (line != NULL)
	{
	printf("[%s]\n", line);
	char *line = get_next_line(fd);
	}
	close(fd);
	return 0;
}
