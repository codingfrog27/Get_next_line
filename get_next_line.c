/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:31 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/07/12 18:50:21 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	int		read_ret;

	line = "";
	if (fd < 0 || fd > OPEN_MAX || read(fd, 0, 0) == -1)
		return (NULL);
	if (*buff != '\0')
		line = buff_to_line(buff, line);
	while(nlen(line) == 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		buff[read_ret] = '\0';
		line = buff_to_line(buff, line);
	}
	buff_update(buff);
	if (read_ret == 0 && *line == '\0')
		return (NULL);
	return (line);
}



char	*buff_to_line(char *buff, char *line)
{
	size_t	line_len = strlen(line);
	size_t	buff_end = nlen(buff);
	if (!buff_end)
		buff_end = strlen(buff);
	char	*line2 = malloc(buff_end + line_len + 1);
	if (!line2)
		return (NULL);
	strncpy(line2, line, line_len);
	strncat(line2, buff, buff_end + 1);
	return (line2);
}

void buff_update(char buff[])
{
	size_t	npos;
	size_t	i;

	npos = nlen(buff);
	i = 0;
//	buff[npos] = '\0';
	if (buff[npos + 1] == '\0'){
		bzero(buff, BUFFER_SIZE);
		return ;
	}
	while(buff[npos])
	{
		buff[i] = buff[npos];
		buff[npos] = '\0';
		i++;
		npos++;
	}
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
	for (int i = 0; i < 5; ++i)
	{
	char *line = get_next_line(fd);
	printf("%s", line);
	}
	close(fd);
	return 0;
}
