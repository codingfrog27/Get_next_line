/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:31 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/06/30 13:41:27 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	int		read_ret;

	if (fd < 0 || fd > OPEN_MAX || read(fd, buff, 0) == -1)
		return (NULL);
	if (*buff)
		line = buff_to_line(buff, line);
	while(!strchr(buff, '\n')) //als er iets misgaat veradner naar line maybe uwu
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		buff[read_ret] = '\0';
		buff_to_line(buff, line);

	}
	buff_update //if \n is in the middle of the buffer you need to move the remainder to the start of the buffer

}


char	*buff_to_line(char *buff, char *line)
{
	size_t	line_len = ft_strlen(line);
	size_t	buff_end = strchr(buff, '\n');
	if (!buff_end)
		buff_end = strchr(buff, '\0');

	char	*line2 = malloc(buff_end + line_len);
	copy till buff_end
	return (line2)


void buff_update(char *buff)
{

}

}
int main()
{
	int fd = open("text.txt", O_RDONLY);
	char	*line = gnl(fd);
	while (line != NULL)
	{
	printf("%s\n", line);
	char *line = gnl(fd);
	}
	return 0;
}
